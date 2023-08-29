/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:41:37 by hrahmane          #+#    #+#             */
/*   Updated: 2022/10/25 13:03:56 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	l;

	if (s)
	{
		l = ft_strlen(s);
		i = 0;
		while (s[i] && i < l)
		{
			f(i, &s[i]);
			i++;
		}
	}
}
