/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:19:24 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/23 13:20:54 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buffer, char *readed)
{
	int	bites_read;

	bites_read = read(fd, buffer, BUFFER_SIZE);
	if (bites_read == 0)
		return (NULL);
	buffer[bites_read] = '\0';
	while (bites_read > 0)
	{
		readed = ft_strjoin(readed, buffer);
		if (ft_strchr(readed , '\n'))
			break ;
		bites_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bites_read] = '\0';
	}
	return (readed);
}

char	*ft_proces_line(char *readed)
{
	char	*exit;
	size_t 	line_size;

	if (ft_strchr(readed,'\n'))
		line_size = ft_strchr(readed, '\n') - readed;
	else
		line_size = ft_strlen(readed);
	exit = (char *)malloc(line_size + 2);
	ft_memcpy(exit, readed, line_size + 1);
	exit[line_size + 1] = '\0';
	return (exit);
}

char	*get_next_line(int	fd)
{
	static char	*readed;
	char		*exit;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	if (!ft_strchr(readed, '\n'))
		readed = ft_read_line(fd, buffer, readed);
	if (!readed)
		return (NULL);
	exit = ft_proces_line(readed);
	if (ft_strchr(readed, '\n'))
		ft_memcpy(readed, ft_strchr(readed, '\n') + 1, ft_strlen(ft_strchr(readed, '\n') + 1) + 1);
	return (exit);
}



int main()
{
	int	fd;
	fd = open("lorem2.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al leer el archivo");
		return (-1);
	}
	// get_next_line(fd);
	// get_next_line(fd);
	printf("\nEl tamaño del buffer que etsoy usando es de: %i\n", BUFFER_SIZE);
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");
	close(fd);
}

