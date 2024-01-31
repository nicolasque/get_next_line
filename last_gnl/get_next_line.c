/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:40:52 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/31 17:20:03 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *readed)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bites_read;

	bites_read = BUFFER_SIZE;
	readed = (char *)malloc(1);
	readed[0] = '\0';
	while (bites_read != 0)
	{
		bites_read = read(fd, buffer, BUFFER_SIZE);
		if (readed == NULL && bites_read == 0)
			return (NULL);
		if (bites_read == -1)
			return (free(readed), NULL);
		buffer[bites_read] = '\0';
		readed = ft_strjoin(readed, buffer);
	}
	if (ft_strlen(readed) == 0)
		return (free(readed), NULL);
	return (readed);
}

char	*ft_get_line(char *readed)
{
	char	*line;
	int		line_size;

	if (ft_strchr(readed,  '\n'))
		line_size = (ft_strchr(readed, '\n') - readed + 1); //Espacio para el /n y el /0
	else
		line_size = (ft_strlen(readed));
	if (line_size == 0)
		return (NULL);
	line = (char *)malloc(line_size * sizeof(char) + 1);
	ft_memcpy(line, readed, line_size + 1);
	line[line_size] = '\0';
	return (line);
}

char	*ft_prepare_readed(char *readed)
{
	char	*new_readed;
	int		new_size;

	if (ft_strchr(readed, '\n'))
		new_size = ft_strlen(readed) - (ft_strchr(readed, '\n') - readed) + 2;
	else
		new_size = ft_strlen(readed);
	new_readed = (char *)malloc(new_size + 1);
	if (ft_strchr(readed, '\n'))
		ft_memcpy(new_readed, ft_strchr(readed, '\n') + 1, new_size);
	new_readed[new_size] = '\0';
	if (!readed)
		return (NULL);
	free(readed);
	return (new_readed);
}

char	*get_next_line(int fd)
{
	static char	*readed = NULL;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, readed, 0) < 0)
		return (NULL);
	if (!readed)
		readed = ft_read_line(fd, readed);
	line = ft_get_line(readed);
	if (ft_strlen(readed) > 0)
		readed = ft_prepare_readed(readed);
	if (ft_strlen(readed) == 0 && line == NULL)
		return (free(readed), NULL);
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

// // 	printf("\nEl tamaño del buffer que etsoy usando es de: %i\n", BUFFER_SIZE);
// 	int i = -1;
// 	// while (i++ < 15)
// 	// {
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
// 		printf("llamada: %s__FIN\n\n", get_next_line(fd));
// 		printf("\n============================================\n");
// 		printf("llamada: %s__FIN\n\n", get_next_line(fd));
// 		printf("\n============================================\n");

// 	// }
// 	close(fd);
//  }
