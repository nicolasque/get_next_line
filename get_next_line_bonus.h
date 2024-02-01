/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:32:21 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/01 19:38:19 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <strings.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif // BUFFER_SIZE

# ifndef FD_OPEN
#  define FD_OPEN 256
# endif //FD_OPEN


char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
void	ft_memcpy(char *copy, char *origin, size_t len);
char	*ft_strchr(char *str, char chr);
char	*get_next_line(int fd);

#endif //GET_NEXT_LINE_BONUS_H