/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:09:02 by hrahmane          #+#    #+#             */
/*   Updated: 2022/10/24 12:59:55 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(long int n)
{
	if (n < 0)
	{
		return (1 + ft_count(-n));
	}
	if (n / 10 == 0)
	{
		return (1);
	}
	return (1 + ft_count(n / 10));
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	nb;

	nb = (long int)n;
	len = ft_count(n);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	len--;
	while (nb > 0)
	{
		str[len] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (str);
}
