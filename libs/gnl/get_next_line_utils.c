/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:36:41 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/28 13:03:46 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_isnewline(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*gnljoin(char *s1, char *s2)
{
	char	*cat;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s1 == NULL)
	{
		s1 = malloc (1);
		*s1 = '\0';
	}
	cat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	free(s1);
	while (s2[j] != '\0')
		cat[i++] = s2[j++];
	cat[i] = '\0';
	return (cat);
}

char	*gnlsubstr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		sub[0] = '\0';
		return (sub);
	}
	sub = malloc ((len + 1) * sizeof(char));
	if (s == NULL || sub == NULL)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
