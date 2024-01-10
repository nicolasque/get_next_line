/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:58:15 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/10 20:51:32 by nquecedo         ###   ########.fr       */
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

	if (!s1 || !s2)
		return (NULL);
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

char	*ft_strdup(const char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(ft_strlen(str) + 1);
	if (new_str == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}


int	ft_is_nl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str ++;
	}
	return (0);
}

char	*ft_strchr(const char *str, unsigned char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_read_line(int fd, char *buffer)
{
	char	*line;
	char	*temp;
	int		bites_read;

	line = ft_strdup("");
	bites_read = BUFFER_SIZE;
	while (!ft_is_nl(line) && bites_read == BUFFER_SIZE)
	{
		bites_read = read(fd, buffer, BUFFER_SIZE);
		if (bites_read == -1)
		{
			free(line);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(line, buffer);
		free(line);
		line = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	// char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, buffer);
	if (!line)
		return (NULL);
	return (line);
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
	printf("\nEl tamaño del buffer que etsoy usando es de: %i\n", BUFFER_SIZE);
	printf("Otra llamada:\n%s __FIN\n\n", get_next_line(fd));
	printf("Otra llamada:\n%s __FIN\n\n", get_next_line(fd));
	printf("Otra llamada:\n%s __FIN\n\n", get_next_line(fd));
	
}