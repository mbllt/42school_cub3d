/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:59:32 by mballet           #+#    #+#             */
/*   Updated: 2021/03/01 09:10:08 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_null(char **line)
{
	if (!((*line) = malloc(sizeof(char) * 1)))
		return (0);
	(*line)[0] = 0;
	return (1);
}

ssize_t	free_temp(char **temp, ssize_t read_return)
{
	if (*temp)
		free(*temp);
	(*temp) = NULL;
	return (read_return);
}

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		i;

	i = 0;
	tab = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	size_t	i;
	size_t	j;

	if (!s1)
		tab = ft_strdup(s2);
	if (s2[0] == '\0' && (tab = malloc(sizeof(char) * 1)))
		return (!(tab) ? NULL : tab);
	if (s1 && s2)
	{
		if (!(tab = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		i = -1;
		while (s1[++i])
			tab[i] = s1[i];
		j = 0;
		while (s2[j])
			tab[i++] = s2[j++];
		tab[i] = '\0';
	}
	if (s1)
		free(s1);
	return (tab);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
