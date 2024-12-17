/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:41:29 by camerico          #+#    #+#             */
/*   Updated: 2024/12/17 15:44:31 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

// si la nouvelle ligne est deja remplie , strjoin s1(line) et s2(buffer)
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		k;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s1[i] && (i == 0 || s1[i - 1] != '\n'))
		s3[k++] = s1[i++];
	while (s2[j])
		s3[k++] = s2[j++];
	s3[k] = '\0';
	return (s3);
}

int	main(int argc, char **argv)
{
	(void) argc;
	char	*tmp;

	tmp = ft_strjoin(argv[1], argv[2]);
	printf("%s", tmp);
	free(tmp);
	return (0);
}