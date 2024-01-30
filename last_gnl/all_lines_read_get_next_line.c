/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_lines_read_get_next_line.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 17:40:52 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/30 19:24:49 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd)
{
	char	*readed;
	char	buffer[BUFFER_SIZE + 1];
	int		bites_read;

	bites_read = BUFFER_SIZE;
	readed = malloc(1);
	readed[0] = '\0';
	while (bites_read != 0)
	{
		bites_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bites_read] = '\0';
		readed = ft_strjoin(readed, buffer);
	}
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*readed = NULL;
	char	*line;

	readed = ft_read_line(fd);

	return (readed);
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

	printf("\nEl tamaño del buffer que etsoy usando es de: %i\n", BUFFER_SIZE);
	int i = -1;
	// while (i++ < 6){
	printf("llamada:\n%s__FIN\n\n", get_next_line(fd));
	// get_next_line(fd);
	// printf("\n============================================\n");
	// get_next_line(fd);
	// printf("\n============================================\n");
	// get_next_line(fd);
	// printf("\n============================================\n");
	// get_next_line(fd);
	// printf("\n============================================\n");
	// }
	close(fd);
}
