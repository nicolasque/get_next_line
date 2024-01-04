/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:58:15 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/04 02:40:43 by nico             ###   ########.fr       */
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
	char	*output;
	size_t	i;
	int		nl_found;

	nl_found = 0;
	output = NULL;
	while (read(fd, buffer, BUFFER_SIZE))
	{
		i = 0;
		output = ft_strjoin(output, buffer);
		while (output[i])
		{
			if (output[i] == '\n')
				nl_found = 1;
			i++;
		}
		if (nl_found)
			break ;
	}
	
	printf("\n the output is: %s\n", output);
	return ("hola");
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
	return 0;
}
