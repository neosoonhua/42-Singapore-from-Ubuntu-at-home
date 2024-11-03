/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:45:00 by sneo              #+#    #+#             */
/*   Updated: 2024/10/14 16:45:02 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <signal.h>

extern int	g_last_exit_status;

typedef struct stack
{
	int		*io;
	int		*pf;
	int     prev_fd;
	char	**env;
}	t_s;

typedef t_s*	t_p;

int		print_2d_char_arr(char **arr);
// void	*free_what(t_info *node, char **arr_2d, char **also_2d);
int		free_many(char *arr1, char **arr2, char **arr3);
int		free_p_and_many(t_p p, char *arr1, char **arr2, char **arr3);
void	close_pipe_close_file_return(t_p p);
t_p		calloc_p(char **my_env);
char	**get_poss_paths(t_p p);
char	*get_path(char **args, char **poss_paths);
char	*get_shell(t_p p);
int		handle_heredoc(t_p p, char *delimiter);
void	remove_redirection_tokens(char **args, int i);
int		handle_redirections(t_p p, char **args);
int 	execute_single_command(t_p p, char **cmds, int i);
int		execute_first_command(t_p p, char **cmds, int i);
int		execute_last_command(t_p p, char **cmds, int i);
int		execute_middle_command(t_p p, char **cmds, int i);
char	*get_env_var_name(char *line);
char	*getenv_value(char *var, t_p p);
char	*command_substitution(char *cmd, t_p p);
char	*expand_variable(char *line, t_p p);
char	*read_pipe_output(int fd);
int		skip_quotes(char *s, int i);
int		count_words(char *s, char *set);
char	**sep_by_pipe(char *str);
char	**split_cmd(char const *s, char c);
char	**split_pipe_redir(char *s, char *set);
int 	trim_and_run(char **cmds, t_p p);
char	**dupli(char **env);
#endif
