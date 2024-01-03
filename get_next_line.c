/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:58:15 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/03 23:03:15 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*exit;
	int		i;

	if (!s2)
		return (NULL);
	if (!s1)
		s1 = "";
	exit = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (exit == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		exit[i++] = *s1++;
	while (*s2)
		exit[i++] = *s2++;
	exit[i] = '\0';
	return (exit);
}


char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	// size_t	bites_read;
	char	*output;
	
	read(fd, buffer, BUFFER_SIZE);
	output = ft_strjoin(output, buffer);

	printf("%s", output);
	
	return ("hola");
}

int main()
{
	// int	fd;

	// // fd = open("lorem.txt");
	// if (fd == -1)
	// {
	// 	printf("Error al leer el archivo");
	// 	return (-1);
	// }
	
	get_next_line(0);
	return 0;
}
