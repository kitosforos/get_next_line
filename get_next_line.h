/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalo <marcoalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:47:41 by marcoalo          #+#    #+#             */
/*   Updated: 2025/01/21 20:06:10 by marcoalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);

int				ft_strlen(char *s);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strrchr(char *s, int c);

char			*ft_substr(char *s, int start, int len);

void			*ft_calloc(size_t nitems, size_t size);
#endif
