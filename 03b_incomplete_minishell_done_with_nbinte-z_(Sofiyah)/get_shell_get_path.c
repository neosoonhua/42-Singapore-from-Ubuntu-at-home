/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shell_get_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:58:34 by sneo              #+#    #+#             */
/*   Updated: 2024/10/26 18:58:35 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_poss_paths(t_p p)
{
	char	*substr;
	char	**split;
	int		i;

	i = 0;
	while (p->env[i])
	{
		if (ft_strnstr(p->env[i], "PATH=", 5))
		{
			substr = ft_substr(p->env[i], 5, ft_strlen(p->env[i]) - 5);
			split = ft_split(substr, ':');
			free(substr);
			return (split);
		}
		i++;
	}
	return (NULL);
}

char	*get_path(char **args, char **poss_paths)
{
	char	*temp_path;
	char	*path;

	if (access(args[0], F_OK) != -1 && access(args[0], X_OK) != -1)
		return (args[0]);
	else
	{
		while (*poss_paths)
		{
			temp_path = ft_strjoin(*poss_paths++, "/");
			path = ft_strjoin(temp_path, args[0]);
			free(temp_path);
			if (access(path, F_OK) != -1 && access(path, X_OK) != -1)
				return (path);
			else
				free(path);
		}
	}
	return (NULL);
}

char	*get_shell(t_p p)
{
	int		i;

	i = 0;
	while (p->env[i])
	{
		if (ft_strnstr(p->env[i], "SHELL=", 6))
			return (last_word(p->env[i], '/'));
		i++;
	}
	return (NULL);
}
