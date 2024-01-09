/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:59:24 by nquecedo          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/08 14:20:48 by nquecedo         ###   ########.fr       */
=======
/*   Updated: 2024/01/04 02:27:13 by nico             ###   ########.fr       */
>>>>>>> fcde580fa999371ac1eef364d9809223f5c99063
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif // BUFFER_SIZE

char	*get_next_line(int fd);

#endif //GET_NEXT_LINE