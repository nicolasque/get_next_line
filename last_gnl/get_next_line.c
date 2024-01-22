/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:19:24 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/22 21:10:24 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *buffer, char *readed)
{
	int	bites_read;

	bites_read = read(fd, buffer, BUFFER_SIZE);
	while (bites_read > 0)
	{
		buffer[bites_read] = '\0';
		readed = ft_strjoin(readed, buffer);
		if (ft_strchr(readed , '\n'))
			break ;
		bites_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (readed);
}

char	*ft_proces_line(char *readed)
{
	char	*exit;
	size_t 	line_size;

	line_size = ft_strchr(readed, '\n') - readed;
	exit = (char *)malloc(line_size + 2);
	ft_memcpy(exit, readed, line_size + 1);
	exit[line_size + 1] = '\0';
	readed = ft_strchr(readed, '\n');
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
	exit = ft_proces_line(readed);
	readed = ft_strchr(readed, '\n');
	return (exit);
}


int main()
{
	int	fd;
	fd = open("lorem.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al leer el archivo");
		return (-1);
	}
	// get_next_line(fd);
	printf("\nEl tamaño del buffer que etsoy usando es de: %i\n", BUFFER_SIZE);
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");
	close(fd);
}

