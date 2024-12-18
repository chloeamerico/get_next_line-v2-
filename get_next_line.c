/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:25:50 by camerico          #+#    #+#             */
/*   Updated: 2024/12/18 15:51:53 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*line;
	static char	*stash;
	char	*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = NULL;
	line = ft_strjoin_free(stash, line);
	buffer = read_to_buffer(fd, line, buffer, stash);
	line = fill_line();
	
}

char	*read_to_buffer(int *fd, char *line, char *buffer, char *stash)
{
	int	b_read;

	b_read = 1;
	while((!ft_strchr(buffer, '\n')) && b_read != 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
			return (free(buffer), NULL);
		buffer[b_read] = '\0';
		fill_stash_and_line(buffer, stash, line);
	}
	return (buffer);
}

void	fill_stash_and_line(char *buffer, char *stash, char *line)
{
	int	i;
	int j;
	int k;

	while(buffer[i] != '\n' && buffer[i])
	{
		line[k++] = buffer[i++];
	}
	if (buffer[i] == '\n')
		line[k++] = buffer[i++];
	while(buffer[i])
	{
		stash[j++] = buffer[i++];
	}
	buffer = 0;
	stash[j] = '\0';
}


char	fill_line(char *line, char *buffer)
{
	if (buffer[b_read] != '\n')
		ft_strjoin_free(line, buffer);
	else
	{
		ft
	}
	
}