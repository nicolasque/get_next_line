/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:58:15 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/22 12:48:59 by nquecedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, void *src, size_t count)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;

	if (!dest && !src)
		return (NULL);
	char_src = (unsigned char *)src;
	char_dest = (unsigned char *)dest;
	if (char_dest < char_src)
	{
		while (count--)
			*char_dest++ = *char_src++;
	}
	else
	{
		char_dest += count;
		char_src += count;
		while (count--)
			*(--char_dest) = *(--char_src);
	}
	return (dest);
}
size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size > 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
		size--;
	}
	if (size != 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*output;

	if (s == NULL)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
		
	if (ft_strlen(s) < start)
		{
			output = malloc(1);
			output[0] = '\0';
			return (output);
		}
	output = malloc(len + 1 * sizeof(char));
	if (output == NULL)
		return (NULL);
		
	ft_strlcpy(output, s + start, len + 1);
	return (output);
}

char	*ft_strdup(char *str)
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

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	new_c;
	unsigned char	*char_str;

	char_str = (unsigned char *)str;
	new_c = c;
	while (n--)
		*char_str++ = new_c;
	return (str);
}

char	*ft_strchr(char *str, unsigned char c)
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

char	*ft_strrchr(char *str, unsigned char c)
{
	int	i;

	i = ft_strlen(str);
	str += i;
	while (i-- >= 0)
	{
		if (*str == c)
			return ((char *)str);
		str --;
	}
	return (NULL);
}

// char	*ft_read_line(int fd, char *buffer)
// {
// 	char	*line;
// 	char	*temp;
// 	int		bites_read;

// 	line = ft_strdup("");
// 	if (!line)
// 		return (NULL);
// 	bites_read = BUFFER_SIZE;
// 	if (ft_strchr(buffer, '\n') != 0)
// 	{
// 		line = ft_strjoin(line, ft_strchr(buffer, '\n') + 1);
// 		ft_memmove(buffer, line + 1, ft_strlen(line + 1) + 1);
// 	}
// 	while (!ft_is_nl(buffer) && bites_read == BUFFER_SIZE)
// 	{
// 		bites_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bites_read == -1 || bites_read == 0)
// 			return (NULL);
// 		buffer[bites_read] = '\0';
// 		temp = ft_strjoin(line, buffer);
// 		if (temp == NULL)
// 		{
// 			free(line);
// 			return (NULL);
// 		}
// 		free(line);
// 		line = temp;
// 	}
// 	return (line);
// }


char	*ft_read_line(int fd, char *buffer)
{
    char	*line;
    char	*temp;
    int		bites_read;
    char	*new_line_ptr;

    line = ft_strdup("");
    if (!line)
        return (NULL);
    bites_read = BUFFER_SIZE;
    new_line_ptr = ft_strchr(buffer, '\n');
    if (new_line_ptr != NULL)
    {
        line = ft_strjoin(line, new_line_ptr + 1);
        ft_memmove(buffer, line + 1, ft_strlen(line + 1) + 1);
    }
    while (!ft_is_nl(buffer) && bites_read == BUFFER_SIZE)
    {
        bites_read = read(fd, buffer, BUFFER_SIZE);
        if (bites_read == -1)
            return (NULL);
        buffer[bites_read] = '\0';
        temp = ft_strjoin(line, buffer);
        if (temp == NULL)
        {
            free(line);
            return (NULL);
        }
        free(line);
        line = temp;
    }
    return (line);
}



char *proces_line(char *str)
{
	char	*newline_pos;
	size_t	len;

	newline_pos = ft_strchr(str, '\n');
	if (newline_pos != NULL)
	{
		len = newline_pos - str;
		return ft_substr(str, 0, len + 1);
	}
	else
		return (ft_substr(str, 0, ft_strlen(str) + 1));
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*line;
	char			*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read_line(fd, buffer);
	if (!line)
	{	
		free(line);
		return (NULL);
	}
	new_line =  proces_line(line);
	free(line);
	return (new_line);
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
	printf("Otra llamada:\n%s__FIN\n\n", get_next_line(fd));
	printf("\n============================================\n");

}