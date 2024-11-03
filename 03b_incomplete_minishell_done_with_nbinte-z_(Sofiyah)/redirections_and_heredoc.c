/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_and_heredoc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:56:31 by sneo              #+#    #+#             */
/*   Updated: 2024/10/26 18:56:33 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	one_if_in_matching_quotes(char *delimiter)
{
	if (delimiter[0] == '\'' && delimiter[ft_strlen(delimiter) - 1] == '\'')
		return (1);
	else if (delimiter[0] == '\"' && delimiter[ft_strlen(delimiter) - 1] == '\"')
		return (1);
	return (0);
}

int	handle_heredoc(t_p p, char *delimiter)
{
	int		fd;
	char	*line;
	char	*accumulated_content;
	char	*expanded_content;
	int		matching_quotes;

	matching_quotes = one_if_in_matching_quotes(delimiter);
	if (matching_quotes)
		delimiter = ft_substr(delimiter, 1, ft_strlen(delimiter) - 2);

	fd = open("/tmp/heredoc.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (-1);

	accumulated_content = ft_strdup(""); // Initialize empty accumulated content

	// Collect all heredoc input until the delimiter
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break;
		}
		accumulated_content = ft_strjoin(accumulated_content, line);
		accumulated_content = ft_strjoin(accumulated_content, "\n");
		free(line);
	}
	
	// Expand variables and perform command substitutions if no matching quotes
	if (!matching_quotes)
		expanded_content = expand_variable(accumulated_content, p);
	else
		expanded_content = ft_strdup(accumulated_content);

	// Write expanded content to the temporary heredoc file
	write(fd, expanded_content, ft_strlen(expanded_content));
	free(accumulated_content);
	free(expanded_content);
	close(fd);

	// Set up heredoc file for reading as input
	fd = open("/tmp/heredoc.tmp", O_RDONLY);
	if (fd < 0)
		return (-1);
	dup2(fd, p->io[0]);
	close(fd);
	unlink("/tmp/heredoc.tmp");
	return (0);
}

void	remove_redirection_tokens(char **args, int i)
{
	// Shift the command array to remove the redirection token and filename
	while (args[i] && args[i + 2])
	{
		args[i] = args[i + 2];
		i++;
	}
	args[i] = NULL;  // Null terminate the array after shifting
	args[i + 1] = NULL;
}

int	handle_redirections(t_p p, char **args)
{
	int	i;
	int	redir_type;
	
	i = 0;
	redir_type = 0;
	while (args[i])
	{
		if (ft_strcmp(args[i], "<") == 0)
		{
			redir_type = 1;
			p->io[0] = open(args[i + 1], O_RDONLY);
			if (p->io[0] < 0)
			{
				ft_printf(2, "Could not open input file: %s\n", args[i + 1]);
				return (-1);
			}
			dup2(p->io[0], STDIN_FILENO);
			close(p->io[0]);
			remove_redirection_tokens(args, i);
		}
		else if (ft_strcmp(args[i], ">") == 0)
		{
			redir_type = 2;
			p->io[1] = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (p->io[1] < 0)
			{
				ft_printf(2, "Could not open output file: %s\n", args[i + 1]);
				return (-1);
			}
			dup2(p->io[1], STDOUT_FILENO);
			close(p->io[1]);
			remove_redirection_tokens(args, i);
		}
		else if (ft_strcmp(args[i], ">>") == 0)
		{
			redir_type = 3;
			p->io[1] = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (p->io[1] < 0)
			{
				ft_printf(2, "Could not open output file: %s\n", args[i + 1]);
				return (-1);
			}
			dup2(p->io[1], STDOUT_FILENO);
			close(p->io[1]);
			remove_redirection_tokens(args, i);
		}
		else if (ft_strcmp(args[i], "<<") == 0)
		{
			redir_type = 4;
			if (handle_heredoc(p, args[i + 1]) == -1)
			{
				ft_printf(2, "Could not open heredoc\n");
				return (-1);
			}
			if (p->io[1] < 0)
				return (-1);
			dup2(p->io[0], STDIN_FILENO);
			remove_redirection_tokens(args, i);
		}
		else
			i++;
	}
	return (redir_type);
}
