/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 08:01:18 by hrahmane          #+#    #+#             */
/*   Updated: 2022/10/25 13:12:56 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	l;
	unsigned int	i;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	str = (char *)malloc(l + 1);
	if (!str)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] && i < l)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
