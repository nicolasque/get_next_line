/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:31:33 by nquecedo          #+#    #+#             */
/*   Updated: 2024/02/01 19:40:29 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_fd(char *buffer, char *line, int fd)
{
	int	bites_read;

	bites_read = BUFFER_SIZE;
	if (ft_strlen(buffer) > 0)
		line = ft_strjoin(line, buffer);
	while (!ft_strchr(buffer, '\n') && bites_read != 0)
	{
		bites_read = read(fd, buffer, BUFFER_SIZE);
		if (bites_read < 0)
		{
			buffer[0] = '\0';
			return (free(line), NULL);
		}
		buffer[bites_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

char	*ft_prepare_line(char *line)
{
	char	*new_line;
	int		new_size;

	if (ft_strchr(line, '\n'))
		new_size = ft_strchr(line, '\n') - line + 1;
	else
		new_size = ft_strlen(line);
	if (new_size == 0)
		return (free(line), NULL);
	new_line = (char *)malloc((sizeof(char) * new_size) + 1);
	if (!new_line)
		return (NULL);
	ft_memcpy(new_line, line, new_size);
	new_line[new_size] = '\0';
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[FD_OPEN][BUFFER_SIZE + 1];
	char		*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	*line = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0 || FD_OPEN < fd)
		return (free(line), NULL);
	line = ft_read_fd(buffer[fd], line, fd);
	if (line == NULL)
		return (NULL);
	line = ft_prepare_line(line);
	if (ft_strchr(buffer[fd], '\n'))
		ft_memcpy(buffer[fd], ft_strchr(buffer[fd], '\n') + 1, \
			ft_strlen(ft_strchr(buffer[fd], '\n') + 1) + 1);
	return (line);
}

// int main()
// {
// 	int	fd;
// 	fd = open("lorem2.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error al leer el archivo");
// 		return (-1);
// 	}
// 		printf("llamada: %s__FIN\n\n", get_next_line(fd));
// 		printf("\n============================================\n");
// 		printf("llamada: %s__FIN\n\n", get_next_line(fd));
// 		printf("\n============================================\n");
// 		printf("llamada: %s__FIN\n\n", get_next_line(fd));
// 		printf("\n============================================\n");
// 		printf("llamada: %s__FIN\n\n", get_next_line(fd));
// 		printf("\n============================================\n");
// 		printf("llamada: %s__FIN\n\n", get_next_line(fd));
// 		printf("\n============================================\n");
// 		printf("llamada: %s__FIN\n\n", get_next_line(fd));
// 		printf("\n============================================\n");
// 		printf("llamada: %s__FIN\n\n", get_next_line(fd));
// 		printf("\n============================================\n");
// 	close(fd);
//  }
