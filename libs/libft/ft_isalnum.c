/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 09:00:25 by hrahmane          #+#    #+#             */
/*   Updated: 2022/10/15 16:13:56 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int n)
{
	if (ft_isdigit(n) || (ft_isalpha(n)))
	{
		return (1);
	}
	else
		return (0);
}
