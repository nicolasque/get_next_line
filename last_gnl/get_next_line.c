/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:19:24 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/22 18:06:06 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_read_line(int fd, char *buffer, char *readed)
// {
// 	int	bites_read;

	
// 	return (readed);
// }

char	*get_next_line(int	fd)
{
	static char	*readed = "hola  mnod";
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, BUFFER_SIZE) < 0)
		return (NULL);
	
	// readed = ft_read_line(fd, buffer, readed);
	printf("%s", ft_strchr());

	return (NULL);
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
	get_next_line(fd);
// 	printf("\nEl tamaño del buffer que etsoy usando es de: %i\n", BUFFER_SIZE);
// 	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
// 	printf("\n============================================\n");
}
