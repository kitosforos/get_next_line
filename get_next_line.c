/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalo <marcoalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:36:49 by kitos             #+#    #+#             */
/*   Updated: 2025/01/21 20:04:37 by marcoalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_remainder(char *remainder)
{
	int		i;
	char	*new_rem;

	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_rem = ft_substr(remainder, i + 1, ft_strlen(remainder));
	free(remainder);
	return (new_rem);
}

char	*get_clean_line(char *remainder)
{
	int		i;
	char	*line;

	if (!remainder[0])
		return (NULL);
	i = 0;
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;
	line = ft_substr(remainder, 0, i);
	if (remainder[i] == '\n')
		line[i] = remainder[i];
	return (line);
}

char	*read_into_remainder(int fd, char *remainder)
{
	char	*buff;
	int		readed;

	if (!remainder)
		remainder = ft_calloc(sizeof(char), 1);
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed = 1;
	while (!ft_strrchr(buff, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buff);
			free(remainder);
			return (NULL);
		}
		buff[readed] = '\0';
		remainder = ft_strjoin(remainder, buff);
	}
	free(buff);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	remainder = read_into_remainder(fd, remainder);
	if (!remainder)
		return (NULL);
	line = get_clean_line(remainder);
	remainder = update_remainder(remainder);
	return (line);
}
