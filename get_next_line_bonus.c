/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalo <marcoalo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:13:46 by marcoalo          #+#    #+#             */
/*   Updated: 2025/01/20 13:14:39 by marcoalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*update_remainder(char *remainder)
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

static char	*get_clean_line(char *remainder)
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

static char	*process_remainder(char *remainder, char *buf, int bytes_read)
{
	char	*temp;

	if (bytes_read == -1 || (bytes_read == 0 && (!remainder || !*remainder)))
	{
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
	return (remainder);
}

static char	*read_into_remainder(int fd, char *remainder)
{
	char	*buf;
	int		bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(remainder, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		remainder = process_remainder(remainder, buf, bytes_read);
		if (!remainder)
			break ;
	}
	free(buf);
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remainders[MAX_FD];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
		return (NULL);
	remainders[fd] = read_into_remainder(fd, remainders[fd]);
	if (!remainders[fd])
		return (NULL);
	line = get_clean_line(remainders[fd]);
	remainders[fd] = update_remainder(remainders[fd]);
	return (line);
}
