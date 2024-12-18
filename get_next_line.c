/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:25:50 by camerico          #+#    #+#             */
/*   Updated: 2024/12/18 20:05:49 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char	*line;
	static char	*stash;
	char	buffer[BUFFER_SIZE + 1];
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	line = ft_strjoin_free(stash, line);
	read_to_buffer(buffer, fd, line, stash);
	read_to_buffer(buffer, fd, line, stash);
	return (line);
}

void	read_to_buffer(char *buffer, int fd, char *line, char *stash)
{
	int	b_read;

	b_read = 1;
	while((!ft_strchr(buffer, '\n')) && b_read != 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(line);
			return;
		}
		buffer[b_read] = '\0';
		line = ft_strjoin_free(line, buffer);
	}
	fill_stash(line, stash);
}

void	fill_stash(char *line, char *stash)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while(line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	while(line[i])
	{
		stash[j] = line[i];
		line[i]= '\0';
		i++;
		j++;
	}
	stash[j] = '\0';
}

int	main(void)
{
	int fd;
	char *str;

	fd = open("test3.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("%s", "une erreur s'est produite dans l'ouverture du fichier");
		return (1);
	}
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
	return (0);
}