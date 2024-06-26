/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlagrini <mlagrini@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:42:23 by mlagrini          #+#    #+#             */
/*   Updated: 2023/08/28 13:04:10 by mlagrini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*readnsave(int fd, char *holder)
{
	char	*buff;
	int		count;

	buff = malloc (BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	count = 1;
	while (count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free (holder);
			free (buff);
			return (NULL);
		}
		buff[count] = '\0';
		holder = gnljoin(holder, buff);
		if (ft_isnewline(holder))
			break ;
	}
	free (buff);
	return (holder);
}

char	*readline(char *buff)
{
	char	*line;
	int		index;

	index = 0;
	if (buff[index] == '\0')
		return (NULL);
	while (buff[index] != '\0' && buff[index] != '\n')
		index++;
	if (buff[index] == '\n')
	{
		line = gnlsubstr(buff, 0, (index + 2));
		line[index] = '\n';
		line[index + 1] = '\0';
	}
	else
	{
		line = gnlsubstr(buff, 0, (index + 1));
		line[index] = '\0';
	}
	return (line);
}

char	*newline(char *buff)
{
	char	*newholder;
	int		index;

	index = 0;
	while (buff[index] != '\0' && buff[index] != '\n')
		index++;
	if (buff[index] == '\0')
	{
		free (buff);
		return (NULL);
	}
	newholder = gnlsubstr(buff, (index + 1), (ft_strlen(buff) - index + 1));
	free (buff);
	return (newholder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = readnsave(fd, holder);
	if (buff == NULL)
	{
		free(buff);
		holder = NULL;
		return (NULL);
	}
	line = readline(buff);
	holder = newline(buff);
	return (line);
}
