/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:02:37 by hrahmane          #+#    #+#             */
/*   Updated: 2022/10/25 15:05:26 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	i++;
	return (count);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	l;

	l = 0;
	while (s[i] && s[i] != c)
	{
		l++;
		i++;
	}
	return (l);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		wdcount;
	int		i;
	int		k;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	wdcount = ft_wordcount(s, c);
	strings = malloc(sizeof(char *) * (wdcount +1));
	if (!strings)
		return (NULL);
	while (k < wdcount)
	{
		while (s[i] == c)
			i++;
		j = ft_wordlen(s, c, i);
		strings[k] = ft_substr (s + i, 0, j);
		i += j;
		k++;
	}
	strings[wdcount] = 0;
	return (strings);
}
