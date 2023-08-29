/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:08:31 by hrahmane          #+#    #+#             */
/*   Updated: 2022/10/21 17:29:45 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tempdst;
	char	*tempsrc;

	i = 0;
	tempdst = (char *)dst;
	tempsrc = (char *)src;
	if (tempsrc < tempdst)
	{
		while (len--)
			tempdst[len] = tempsrc[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
