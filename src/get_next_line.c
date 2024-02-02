/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktaplin <ktaplin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:41:12 by ktaplin           #+#    #+#             */
/*   Updated: 2023/03/15 19:01:27 by ktaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_size(char *tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp[i] && tmp[i] != '\n')
		i++;
	if (i == 1)
		i = 0;
	return (i);
}

static char	*read_file(int fd, char *tmp)
{
	char	*buf;
	int		read_ret;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (0);
	read_ret = 1;
	while (read_ret > 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret < 0)
		{
			free(buf);
			return (0);
		}
		buf[read_ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
		if (tmp == NULL)
			break ;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (tmp);
}

static char	*get_end(char *tmp, int i)
{
	int		j;
	char	*line;

	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (0);
	}
	line = malloc((sizeof(char) * ft_strlen(tmp) - i) + 1);
	if (line == NULL)
	{
		free(tmp);
		return (0);
	}
	i++;
	j = 0;
	while (tmp[i])
		line[j++] = tmp[i++];
	line[j] = '\0';
	free(tmp);
	return (line);
}

static char	*get_start(char *line, char *tmp, int i)
{
	i = get_size(tmp);
	line = malloc(sizeof(char) * i + 2);
	if (line == NULL)
	{
		free(tmp);
		return (0);
	}
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;
	int			i;

	tmp = 0;
	line = 0;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = read_file(fd, tmp);
	if (!tmp)
		return (0);
	line = get_start(line, tmp, i);
	tmp = get_end(tmp, i);
	if (line[i] == 0)
	{
		free(line);
		return (NULL);
	}
	free(tmp);
	return (line);
}