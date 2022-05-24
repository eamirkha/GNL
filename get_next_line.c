/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamirkha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:55:22 by eamirkha          #+#    #+#             */
/*   Updated: 2022/04/29 13:38:22 by eamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_fd(int fd, char *buffer, char **line)
{
	int	bytes;
	int	i;

	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		*line = free_join(*line, buffer);
		i = 0;
		while (buffer[i] && buffer[i] != '\n')
			i++;
		if (buffer[i] == '\n')
			break ;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (bytes);
}

void	join_nt(char **fline, char **line, char *nt)
{
	*fline = free_join(*fline, *line);
	*fline = free_join(*fline, nt);
	free(*line);
	*line = NULL;
}

int	check_rest(char **rest, char **line, int fd, char **fline)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 0;
	*line = ft_strnew(1);
	*fline = ft_strnew(1);
	if (*rest)
	{
		*line = free_join(*line, *rest);
		free(*rest);
		*rest = NULL;
	}
	bytes = read_fd(fd, buffer, line);
	return (bytes);
}

int	nl_index(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest;
	char		*fline;

	if ((check_rest(&rest, &line, fd, &fline)) <= 0 && ft_strlen(line) == 0)
	{
		free(line);
		free(fline);
		return (0);
	}
	else
	{
		if (line[nl_index(line)] == '\n')
		{
			if (!rest)
				rest = ft_strnew(1);
			line[nl_index(line)] = '\0';
			rest = free_join(rest, &line[nl_index(line) + 1]);
			join_nt(&fline, &line, "\n\0");
		}
		else
			join_nt(&fline, &line, "\0");
	}
	return (fline);
}
