/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:53:11 by camerico          #+#    #+#             */
/*   Updated: 2024/12/18 20:01:33 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return(0);
	i = 0;
	while(s[i])
		i++;
	return(i);
}

// si la nouvelle ligne est deja remplie , strjoin s1(line) et s2(buffer)
char	*ft_strjoin_free(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && s1)
		{
			s3[i] = s1[i];
			i++;
		}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

// recherche la premiere occurence du char c dans *s
// retourne le reste de la string a partir du premier char c trouve (\n)
// verifie s'il y a un \n dan le buffer
int	ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}


