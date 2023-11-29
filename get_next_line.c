/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefuente <cefuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:11:19 by cesar             #+#    #+#             */
/*   Updated: 2023/11/29 14:26:57 by cefuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rope;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rope = buf_to_rope(fd, rope);
	if (!rope)
		return (NULL);
	line = rope_to_line(rope);
	rope = get_next(rope);
	return (line);
}

char	*buf_to_rope(int fd, char *rope)
{
	char	*buf;
	char	*tmp;
	int		rd;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL); 
	rd = 1;
	while (!(ft_strchr(rope, '\n')) && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd == -1)
			return (free(buf), free(rope), NULL);
		buf[rd] = 0;
		if (!rope)
			rope = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(rope, buf);
			free(rope);
			rope = tmp;
		}
	}
	return (free(buf), rope);
}

char	*rope_to_line(char *rope)
{
	int		i;
	char	*line;

	i = 0;
	if (!rope[0])
		return (NULL);
	while (rope[i] != '\n' && rope[i])
		i++;
	line = ft_strndup(rope, i + 1);
	return (line);
}

char	*get_next(char *rope)
{
	char	*next_rope;

	if (!(ft_strchr(rope, '\n')))
		return (free(rope), NULL);
	next_rope = ft_strdup(ft_strchr(rope, '\n') + 1);
	return (free(rope), next_rope);
}
