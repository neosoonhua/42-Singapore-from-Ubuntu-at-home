/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:17:49 by sneo              #+#    #+#             */
/*   Updated: 2024/10/26 19:17:50 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Extracts the environment variable name from line
char	*get_env_var_name(char *line)
{
	int		i = 0;

	// printf("line: %s\n", line);
	while (line[i] && (ft_isalnum(line[i]) || line[i] == '_'))
		i++;
	return (ft_substr(line, 0, i));
}

// Gets the value of an environment variable
char	*getenv_value(char *var, t_p p)
{
	int		i;
	int		len;
	
	len = ft_strlen(var);
	i = 0;
	while (p->env[i])
	{
		if (!ft_strncmp(p->env[i], var, len) && p->env[i][len] == '=')
			return (p->env[i] + len + 1);
		i++;
	}
	// return (ft_strdup(""));  // Return an empty string instead of NULL
    return (NULL);
}

// Reads output from the pipe and returns it as a string
char	*read_pipe_output(int fd)
{
	char	buffer[1024];
	int		bytes_read;
	char	*output;

	output = ft_strdup("");
	while ((bytes_read = read(fd, buffer, 1023)) > 0)
	{
		buffer[bytes_read] = '\0';
		output = ft_strjoin(output, buffer);
	}
	return (output);
}

// Executes a command substitution and returns the output
char *command_substitution(char *cmd, t_p p)
{
    int     pipe_fd[2];
    pid_t   pid;
    char    buffer[1024];
    ssize_t bytes_read;
    char    *result;
    char    *temp_result;
    char    **args;
    char    *path;
    char    **poss_paths;

    result = ft_strdup("");
    if (pipe(pipe_fd) == -1)
        return (NULL);

    pid = fork();
    if (pid == -1)
    {
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        free(result);
        return (NULL);
    }
    if (pid == 0)  // Child process
    {
        close(pipe_fd[0]);         // Close read end of the pipe
        dup2(pipe_fd[1], 1);       // Redirect stdout to pipe write end
        close(pipe_fd[1]);         // Close write end after duplication

        args = split_cmd(cmd, ' ');
        poss_paths = get_poss_paths(p);
        path = get_path(args, poss_paths);

        if (path)
        {
            execve(path, args, p->env);   // Execute the command with p->env
            perror("execve");
            free(path);
        }
        free_many(path, args, poss_paths);
        exit(1);
    }
    else  // Parent process
    {
        close(pipe_fd[1]);  // Close write end of the pipe

        while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer) - 1)) > 0)
        {
            buffer[bytes_read] = '\0';
            temp_result = result;
            result = ft_strjoin(result, buffer);  // Append to result
            free(temp_result);
        }
        close(pipe_fd[0]);
        waitpid(pid, NULL, 0);
    }

    // Remove any trailing newlines from the result
    int len = ft_strlen(result);
    while (len > 0 && result[len - 1] == '\n')
    {
        result[len - 1] = '\0';
        len--;
    }

    return (result);
}

char    *expand_variable(char *line, t_p p)
{
    char    *result;
    char    *expanded;
    char    *var;
    char    *cmd_output;
    int     i;

    result = ft_strdup("");  // Start with an empty string
    i = 0;
    while (line && line[i])  // Check that line isn't NULL
    {
        if (line[i] == '$')
        {
            i++;
            if (line[i] == '(')  // Command substitution case
            {
                i++;
                var = ft_substr(line, i, ft_strchr(line + i, ')') - (line + i));
                cmd_output = command_substitution(var, p);  // Execute command in subshell
                if (cmd_output)
                    expanded = ft_strjoin_free2(result, cmd_output);
                else
                    expanded = ft_strjoin(result, "");  // No output fallback to empty
                i += ft_strlen(var) + 1;
                free(var);
            }
            else if (line[i] == '?')  // Check for "$?" exit status variable
            {
                char *status_str = ft_itoa(g_last_exit_status);
                expanded = ft_strjoin(result, status_str);  // Append exit status
                free(status_str);
                i++;  // Move past '?'
            }
            else  // Environment variable expansion case
            {
                var = get_env_var_name(line + i);
                expanded = ft_strjoin(result, getenv_value(var, p));
                i += ft_strlen(var);
                free(var);
            }
            free(result);
            result = expanded;
        }
        else  // Append regular characters
        {
            expanded = ft_strjoin_free2(result, ft_substr(line, i, 1));
            free(result);
            result = expanded;
            i++;
        }
    }
    return (result);
}
