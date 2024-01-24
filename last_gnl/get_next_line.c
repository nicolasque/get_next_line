/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:19:24 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/24 21:15:01 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_read_line(int fd, char *buffer, char *line)
// {
// 	int		bites_read;

// 	buffer[bites_read] = '\0';
// 	while (bites_read > 0)
// 	{
// 		if (ft_strchr(line, '\n'))
// 			break ;
// 		line = ft_strjoin(line, buffer);
// 		bites_read = read(fd, buffer, BUFFER_SIZE);
// 		buffer[bites_read] = '\0';
// 	}
// 	return (line);
// }

char	*ft_proces_line(char *line)
{
	char 	*output;
	size_t	line_size;

	if (ft_strchr(line, '\n'))
	{
		line_size = ft_strchr(line, '\n') - line;
		if (line_size == 0)
		{
			free(line);
			line = malloc(2);
			line[0] = '\n';
			line[1] = '\0';
			return (line);
		}
	}
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

char	*get_next_line(int	fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bites_read;
	
	bites_read = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || bites_read < 0)
		return (NULL);
	line = malloc(1);
	line = ft_strjoin(line, buffer);
	if (ft_strlen(line) != ft_strlen(buffer))
		return (free(line), NULL);
	while (1)
	{
		if (ft_strchr(buffer, '\n') || bites_read != BUFFER_SIZE)
		{
			if (ft_strchr(buffer, '\n'))
				ft_memcpy(buffer, ft_strchr(buffer, '\n') + 1, ft_strlen(ft_strchr(buffer, '\n') + 1) + 1);
			else
				bzero(buffer, BUFFER_SIZE); //FUNCION ILEGAL
			break ;	
		}
		bites_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bites_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return(ft_proces_line(line));
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
// 	// get_next_line(fd);
// 	// get_next_line(fd);
// 	// printf("\nEl tamaño del buffer que etsoy usando es de: %i\n", BUFFER_SIZE);
// 	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
// 	printf("\n============================================\n");
// 	 printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
// 	printf("\n============================================\n");
// 	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
// 	printf("\n============================================\n");
// 	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
// 	printf("\n============================================\n");
// 	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
// 	printf("\n============================================\n");
// 	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
// 	printf("\n============================================\n");
// 	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
// 	printf("\n============================================\n");
// 	close(fd);
// }
