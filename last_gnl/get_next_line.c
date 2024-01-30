/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:08:56 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/29 19:42:28 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_proces_line(char *line)
{
	char 	*output;
	size_t	line_size;

	if (ft_strchr(line, '\n'))
		line_size = ft_strchr(line, '\n') - line;
	else
		line_size = ft_strlen(line);
	if (line_size == 0)
		return (free(line), NULL);
	output = (char *)malloc(line_size + 2);
	ft_memcpy(output, line, line_size + 1);
	output[line_size + 1] = '\0';
	free(line);
	return (output);
}


char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;	
	int			bites_read;
	
	line = malloc(1);
	line[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	while (1)
	{
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n') || bites_read != BUFFER_SIZE)
		{
			ft_memcpy(buffer, ft_strchr(buffer, '\n') + 1, ft_strlen(ft_strchr(buffer, '\n') + 1) + 1);
			break ;
		}
		bites_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bites_read] = '\0';
	}
	return (ft_proces_line(line));
}
