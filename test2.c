/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:52:18 by camerico          #+#    #+#             */
/*   Updated: 2024/12/18 17:08:13 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*fill_stash_and_line(char *buffer, char *line)
{
	int	i;
	// int j;
	int k;

	i = 0;
	// j = 0;
	k = strlen(line);
	while(buffer[i] != '\n' && buffer[i])
	{
		line[k] = buffer[i];
		k++;
		i++;
	}
	// if (buffer[i] == '\n')
	// 	line[k++] = buffer[i++];
	// while(buffer[i])
	// {
	// 	stash[j++] = buffer[i++];
	// }
	// buffer = 0;
	// stash[j] = '\0';
	return (stash);
}

int	main(void)
{
	char buffer[] = "HELLO";
	// char stash[] = "";
	char line[] = "salut";

	printf("%s", fill_stash_and_line(buffer, line));
	return(0);
}