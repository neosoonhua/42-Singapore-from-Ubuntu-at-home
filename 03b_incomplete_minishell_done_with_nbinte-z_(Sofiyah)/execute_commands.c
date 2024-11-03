/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:01 by sneo              #+#    #+#             */
/*   Updated: 2024/10/26 18:55:05 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int execute_single_command(t_p p, char **cmds, int i)
{
	char	*path;
	char	**args;
	char	**poss_paths;

	args = split_cmd(cmds[i], ' ');
	poss_paths = get_poss_paths(p);
	// Handle redirections
	if (handle_redirections(p, args) == -1)
	{
		close_pipe_close_file_return(p);
		free_p_and_many(p, NULL, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		exit(1);
	}
	path = get_path(args, poss_paths);
	if (!path)
	{
		ft_printf(2, "%s: command not found: %s\n", get_shell(p), args[0]);
		close_pipe_close_file_return(p);
		free_p_and_many(p, path, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		exit(1);
	}
	if (execve(path, args, p->env) == -1)
	{
		free_p_and_many(p, path, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		write(2, "Could not execute command\n", 27);
		exit(1);
	}
	free_p_and_many(p, path, args, poss_paths);
	return (1);
}

int	execute_first_command(t_p p, char **cmds, int i)
{
	char	*path;
	char	**args;
	char	**poss_paths;

	args = split_cmd(cmds[i], ' ');
	poss_paths = get_poss_paths(p);

	// Handle redirections
	if (handle_redirections(p, args) == -1)
	{
		close_pipe_close_file_return(p);
		free_p_and_many(p, NULL, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		exit(1);
	}
	path = get_path(args, poss_paths);
	if (!path)
	{
		ft_printf(2, "%s: command not found: %s\n", get_shell(p), args[0]);
		free_p_and_many(p, path, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		exit(1);
	}
	dup2(p->pf[1], STDOUT_FILENO);  // Redirect stdout to pipe's write end
	if (execve(path, args, p->env) == -1)
	{
		free_p_and_many(p, path, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		write(2, "Could not execute first command\n", 33);
		exit(1);
	}
	return (1);
}

int	execute_last_command(t_p p, char **cmds, int i)
{
	char	*path;
	char	**args;
	char	**poss_paths;
	int		redir_type;

	args = split_cmd(cmds[i], ' ');
	poss_paths = get_poss_paths(p);

	// Handle redirections
	redir_type = handle_redirections(p, args);
	if (redir_type == -1)
	{
		close_pipe_close_file_return(p);
		free_p_and_many(p, NULL, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		exit(1);
	}
	if (redir_type != 4)
		dup2(p->prev_fd, STDIN_FILENO);
	path = get_path(args, poss_paths);
	if (!path)
	{
		ft_printf(2, "%s: command not found: %s\n", get_shell(p), args[0]);
		free_p_and_many(p, path, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		exit(1);
	}
	if (execve(path, args, p->env) == -1)
	{
		free_p_and_many(p, path, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		write(2, "Could not execute last command\n", 32);
		exit(1);
	}
	return (1);
}

int	execute_middle_command(t_p p, char **cmds, int i)
{
	char	*path;
	char	**args;
	char	**poss_paths;
	int		redir_type;

	args = split_cmd(cmds[i], ' ');
	poss_paths = get_poss_paths(p);

	// Handle redirections
	redir_type = handle_redirections(p, args);
	if (redir_type == -1)
	{
		close_pipe_close_file_return(p);
		free_p_and_many(p, NULL, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		exit(1);
	}
	if (redir_type != 4)
		dup2(p->prev_fd, STDIN_FILENO);
	path = get_path(args, poss_paths);
	if (!path)
	{
		ft_printf(2, "%s: command not found: %s\n", get_shell(p), args[0]);
		free_p_and_many(p, path, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		exit(1);
	}

	// Redirect stdout to the next pipe's write end
	dup2(p->pf[1], STDOUT_FILENO);   // Write to next command's input
	close(p->pf[0]);  // Close the unused read end of the current pipe
	if (execve(path, args, p->env) == -1)
	{
		free_p_and_many(p, path, args, poss_paths);
		free_p_and_many(NULL, NULL, NULL, cmds);
		write(2, "Could not execute middle command\n", 33);
		exit(1);
	}
	return (1);
}
