/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcoalo <marcoalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:12:56 by kitos             #+#    #+#             */
/*   Updated: 2025/01/21 20:06:21 by marcoalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

char			*get_next_line(int fd);

int				ft_strlen(char *s);

char			*ft_strjoin(char *s1, char *s2);

char			*ft_strrchr(char *s, int c);

char			*ft_substr(char *s, int start, int len);

void			*ft_calloc(size_t nitems, size_t size);
#endif