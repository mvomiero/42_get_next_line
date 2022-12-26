/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:50:32 by mvomiero          #+#    #+#             */
/*   Updated: 2022/12/26 20:47:56 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_stash(int fd, char *buf, char *stash)
{
	int		read_value;
	char	*char_temp;

	read_value = 1;
	while (read_value != '\0')
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value == -1)
			return (0);
		else if (read_value == 0)
			break ;
		buf[read_value] = '\0';
		if (!stash)
			stash = ft_strdup("");
		char_temp = stash;
		stash = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

static char	*extract_line(char *line)
{
	size_t	pos;
	char	*stash;

	pos = 0;
	while (line[pos] != '\0' && line[pos] != '\n')
		pos++;
	if (line[pos] == '\0' || line [1] == '\0' || line[pos + 1] == '\0')
		return (0);
	stash = ft_substr(line, pos + 1, ft_strlen(line) - pos);
	line[pos + 1] = '\0';
	return (stash);
}

char *get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = extract_stash(fd, buf, stash);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = extract_line(line);
	return (line);
}