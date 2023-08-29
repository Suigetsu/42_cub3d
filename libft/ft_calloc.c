/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrahmane <hrahmane@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 09:58:40 by hrahmane          #+#    #+#             */
/*   Updated: 2022/10/15 16:15:55 by hrahmane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
	{
		return (NULL);
	}
	else
	{
		ft_bzero(ptr, count * size);
	}
	return (ptr);
}
/*#include<stdio.h>
int main()
{
	int *str;
	int i;


	i = 0;
	str = (int *)ft_calloc(6, sizeof(int *));
	while ( i < 6)
	{
		printf("%d\n", str[i]);
		i++;
	}

}*/
