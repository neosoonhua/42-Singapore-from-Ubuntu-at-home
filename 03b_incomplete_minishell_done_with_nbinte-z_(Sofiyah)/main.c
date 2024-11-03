/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:44:51 by sneo              #+#    #+#             */
/*   Updated: 2024/10/14 16:44:54 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_last_exit_status = 0;

int		print_2d_char_arr(char **arr)
{
	while (*arr)
		ft_printf(1, "%s\n", *arr++);
	return (0);
}

char	**dupli(char **env)
{
	int		x;
	int		num_arr;
	char	**new;

	x = 0;
	num_arr = 0;
	while (env[num_arr])
		num_arr++;
	new = (char **)malloc(sizeof(char *) * (num_arr + 1));
	if (!new)
		return (NULL);
	while (env[x])
	{
		new[x] = ft_strdup(env[x]);  // Duplicate each environment variable
		x++;
	}
	new[x] = NULL;  // NULL-terminate the array
	return (new);
}

int	is_builtin(char *command)
{
	if (!ft_strncmp(command, "cd", 2) || !ft_strncmp(command, "export", 6) || !ft_strncmp(command, "unset", 5) || !ft_strncmp(command, "env", 3))
		return (1);
	return (0);
}

int builtin_cd(char **args, t_p p)
{
	if (!args[1] || ft_strlen(args[1]) == 0)  // No path specified
	{
		char *home = getenv_value("HOME", p);
		if (chdir(home) == -1)
		{
			perror("cd");
			return (-1);
		}
		// free_many(home, NULL, NULL);
		return (0);
	}
	else if (chdir(args[1]) == -1)
	{
		perror("cd");  // Display an error if the path is invalid
		return (-1);
	}
	return (0);
}

int	builtin_export(char **args, t_p p)
{
	char	*name;
	char	*value;
	char	*temp;
	char	**temp2;
	int		i;

	if (!args[1]) {
		print_2d_char_arr(p->env);  // Display all environment variables if no arguments
		return (-1);
	}
	name = ft_substr(args[1], 0, ft_strchr(args[1], '=') - args[1]);
	// printf("name: %s\n", name);
	value = ft_strchr(args[1], '=') + 1;
	// printf("value: %s\n", value);
	i = -1;
	while (p->env[++i])
	{
		if (!ft_strncmp((p->env)[i], name, ft_strlen(name)) && (p->env)[i][ft_strlen(name)] == '=') 
		{
			free((p->env)[i]);
			temp = ft_strjoin_free(name, "=");
			// printf("temp: %s\n", temp);
			p->env[i] = ft_strjoin_free(temp, value);
			// free(name);
			return (0);
		}
	}
	// Add a new environment variable if it doesn't exist
	i = 0;
	while (p->env[i])
		i++;
	temp2 = dupli(p->env);
	// printf("temp2:\n");
	// print_2d_char_arr(temp2);
	free_many(NULL, p->env, NULL);
	p->env = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (*temp2)
	{
		// printf("*temp2: %s\n", *temp2);
		p->env[i++] = ft_strdup(*temp2++);
		// printf("p->env[i]: %s\n", p->env[i++]);
	}
	// printf("new p->env:\n");
	// print_2d_char_arr(p->env);
	free_many(NULL, temp2 - i, NULL);
	temp = ft_strjoin_free(name, "=");
	// printf("temp: %s\n", temp);
	p->env[i++] = ft_strjoin_free(temp, value);
	// printf("p->env[i]: %s\n", p->env[i++]);
	p->env[i] = NULL;
	// free(name);
	return (0);
}

int builtin_unset(char **args, t_p p)
{
	int i;
	int len;

	if (!args[1]) 
	{
		write(2, "unset: not enough arguments\n", 29);
		return (-1);
	}
	len = 0;
	while (p->env[len])
		len++;
	i = 0;
	while (i < len)
	{
		if (!ft_strncmp(p->env[i], args[1], ft_strlen(args[1])) && p->env[i][ft_strlen(args[1])] == '=') 
		{
			free(p->env[i]);
			while (i < len - 1)
			{
				p->env[i] = p->env[i + 1];
				i++;
			}
			p->env[len - 1] = NULL;
			break ;
		}
		i++;
	}
	return (0);
}

int 	execute_builtin(char **args, t_p p)
{
	if (!ft_strcmp(args[0], "cd"))
		return (builtin_cd(args, p));
	else if (!ft_strcmp(args[0], "export"))
	{
		// printf("export\n");
		// return (0);
		return (builtin_export(args, p));
	}
	else if (!ft_strcmp(args[0], "unset"))
		return (builtin_unset(args, p));
	else if (!ft_strcmp(args[0], "env"))
	{
		// printf("p->env\n");
		// return (0);
		return (print_2d_char_arr(p->env));
	}
	return (-1);
}

int trim_and_run(char **cmds, t_p p)
{
	pid_t   pid;
	int	 	status;
	int	 	cmd_count;
	int	 	i;
	char	*expanded_cmd;

	cmd_count = 0;
	while (cmds[cmd_count])
		cmd_count++;
	p->prev_fd = -1;
	i = 0;
	if (cmd_count == 1 && is_builtin(cmds[0])) 
	{
		char **args = split_cmd(cmds[0], ' '); // Parse arguments
		execute_builtin(args, p);          // Execute the built-in
		free_p_and_many(NULL, NULL, args, NULL);
		return (1);
	}
	else if (cmd_count == 1)
	{
		expanded_cmd = expand_variable(cmds[0], p);  // Expand variables in the command
		// free(cmds[0]);
		cmds[0] = expanded_cmd;  // Replace original with expanded command
		pid = fork();
		if (pid == 0)
			execute_single_command(p, cmds, 0);  // Handle single command
		waitpid(pid, &status, 0);
		
		if (WIFEXITED(status))
			g_last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_last_exit_status = WTERMSIG(status) + 128;

		// free_p_and_many(p, NULL, NULL, NULL);
		return (1);
	}

	// Handle multiple commands in a pipeline
	while (i < cmd_count)
	{
		if (is_builtin(cmds[0]))
		{
			execute_builtin(cmds, p);
		}
		else
		{
			expanded_cmd = expand_variable(cmds[i], p);  // Expand variables in the command
			cmds[i] = expanded_cmd;  // Replace original with expanded command
			pipe(p->pf);
			pid = fork();
			if (pid == 0)
			{
				if (i == 0)
					execute_first_command(p, cmds, i);  // First command
				else if (i == cmd_count - 1)
					execute_last_command(p, cmds, i);   // Last command
				else
					execute_middle_command(p, cmds, i); // Middle command
			}
			close(p->pf[1]);
			if (p->prev_fd != -1)
				close(p->prev_fd);
			p->prev_fd = p->pf[0];
			waitpid(pid, &status, 0);
			if (WIFEXITED(status))
				g_last_exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				g_last_exit_status = WTERMSIG(status) + 128;
		}
		i++;
	}
	close(p->pf[0]);
	free_p_and_many(NULL, expanded_cmd, NULL, NULL);
	return (1);
}

int	zero_if_exit(char **cmds)
{
	int	 cmd_count;
 
	cmd_count = 0;
	while (cmds[cmd_count])
		cmd_count++;
	if (cmd_count != 1)
		return (1);
   	if (ft_strlen(cmds[0]) == 4)
		return (ft_strncmp("exit", cmds[0], 4));
	else if (ft_strlen(cmds[0]) > 4)
		return (ft_strncmp("exit ", cmds[0], 5));
	else
		return (1);
}

// Signal handler for SIGINT (ctrl-C)
void	handle_sigint(int signum)
{
	(void)signum;
	write(1, "\nminishell: ", 12);  // Display a new prompt on a new line
}

// Signal handler for SIGQUIT (ctrl-\)
void	handle_sigquit(int signum)
{
	(void)signum;
	// Do nothing
}

// Signal handler for EOF (ctrl-D)
int	handle_eof(char *line)
{
	if (!line) // EOF is reached
	{
		write(1, "exit\n", 5);  // Display "exit" and newline
		// free_p_and_many(p, NULL, NULL, NULL);
		return (1);             // Signal to exit the shell
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	**my_env;
	char	*whole_line;
	char	**pipe_splitted;
	t_p	 	p;
	
	(void)ac;
	(void)av;
	my_env = dupli(env);
	p = calloc_p(my_env);
	free_many(NULL, my_env, NULL);
	if (!p || !p->env)
		return (1);

	// Set up signal handlers
	signal(SIGINT, handle_sigint);   // Handle ctrl-C
	signal(SIGQUIT, handle_sigquit); // Ignore ctrl-backslash

	while (1)
	{
		whole_line = readline("minishell: ");
		if (handle_eof(whole_line))  // Exit shell on EOF (ctrl-D)
			break ;
		add_history(whole_line);
		pipe_splitted = sep_by_pipe(whole_line);
		free(whole_line);
		if (!zero_if_exit(pipe_splitted))
			break ;
		if (ft_strncmp("exit", pipe_splitted[0], 4))
			trim_and_run(pipe_splitted, p);
		// free_p_and_many(NULL, NULL, NULL, pipe_splitted);
	}
	free_p_and_many(p, NULL, pipe_splitted, NULL);
	return (0);
}
