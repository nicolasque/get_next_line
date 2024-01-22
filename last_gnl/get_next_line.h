/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:59:24 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/22 12:43:36 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 41
# endif // BUFFER_SIZE

char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
void	ft_memcpy(char *copy, char *origin, size_t len);

char	*get_next_line(int fd);

#endif //GET_NEXT_LINE