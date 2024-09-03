/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:29:35 by sneo              #+#    #+#             */
/*   Updated: 2023/09/28 16:29:35 by sneo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_calloc(size_t nmemb, size_t size)
{
	char			*mem;
	unsigned char	*temp;
	size_t			n;

	if (nmemb <= 0 || size <= 0)
	{
		size = 1;
		nmemb = 0;
	}
	if (nmemb * size > (size_t)INT_MAX)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	temp = (unsigned char *) mem;
	n = nmemb * size;
	while (n-- > 0)
		*(temp++) = (unsigned char) 0;
	return (mem);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	if (len <= 0 || s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	if (start >= slen)
		return (malloc(1));
	str = ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start + i <= slen && s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*extract_line(char **joined, char **temp)
{
	size_t	i;
	char	*line;

	*temp = ft_strdup(*joined);
	ft_free_strs(joined, 0, 0);
	i = 0;
	while ((*temp)[i] && (*temp)[i] != '\n')
		i++;
	if ((*temp)[i] == '\n')
	{
		line = ft_substr(*temp, 0, i + 1);
		*joined = ft_substr(*temp, i + 1, ft_strlen(*temp) - i - 1);
	}
	else
	{
		line = ft_strdup(*temp);
		ft_free_strs(joined, 0, 0);
	}
	ft_free_strs(temp, 0, 0);
	return (line);
}

void	read_and_join(char **joined, char **temp, int fd)
{
	char	*one_read;
	int		num_bytes;

	one_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!one_read)
		return ;
	num_bytes = 1;
	while (num_bytes > 0)
	{
		num_bytes = read(fd, one_read, BUFFER_SIZE);
		if (num_bytes < 0)
		{
			ft_free_strs(&one_read, joined, temp);
			return ;
		}
		one_read[num_bytes] = '\0';
		*temp = ft_strdup(*joined);
		ft_free_strs(joined, 0, 0);
		*joined = ft_strjoin(*temp, one_read);
		ft_free_strs(temp, 0, 0);
		if (ft_strchr(*joined, '\n'))
			break ;
	}
	ft_free_strs(&one_read, 0, 0);
}

char	*get_next_line(int fd)
{
	static char		*joined = NULL;
	char			*line;
	char			*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	temp = NULL;
	read_and_join(&joined, &temp, fd);
	if (joined != NULL && *joined != '\0')
		line = extract_line(&joined, &temp);
	if (!line || *line == '\0')
	{
		ft_free_strs(&joined, &line, &temp);
		return (NULL);
	}
	return (line);
}
