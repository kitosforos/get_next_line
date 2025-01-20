/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalo <marcoalo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:36:49 by kitos             #+#    #+#             */
/*   Updated: 2025/01/20 11:40:04 by marcoalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_remainder(char *remainder)
{
	int		i;
	int		j;
	char	*new_rem;

	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	new_rem = malloc(sizeof(char) * (ft_strlen(remainder) - i + 1));
	if (!new_rem)
		return (NULL);
	i++;
	j = 0;
	while (remainder[i])
		new_rem[j++] = remainder[i++];
	new_rem[j] = 0;
	free(remainder);
	return (new_rem);
}

char	*get_clean_line(char *remainder)
{
	int		i;
	char	*line;

	if (!remainder || !remainder[0])
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] && remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*read_into_remainder(int fd, char *remainder)
{
	char	*buf;
	int		bytes_read;
	char	*temp;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			free(remainder);
			return (NULL);
		}
		buf[bytes_read] = 0;
		if (!remainder)
			remainder = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(remainder, buf);
			free(remainder);
			remainder = temp;
		}
	}
	free(buf);
	if (bytes_read == 0 && (!remainder || !*remainder))
	{
		free(remainder);
		return (NULL);
	}
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
