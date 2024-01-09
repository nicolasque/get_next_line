/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nquecedo <nquecedo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:58:15 by nquecedo          #+#    #+#             */
/*   Updated: 2024/01/09 18:56:06 by nquecedo         ###   ########.fr       */
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

int	ft_is_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_end(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_countfrom_nl(char *str)
{
	int	i;
	int	j;
	int	bool_nl_found;

	i = 0;
	j = 0;
	bool_nl_found = 0;
	while (str[i])
	{
		if (bool_nl_found == 1)
			j++;
		if (str[i] == '\n')
			bool_nl_found = 1;
		i++;
	}
	return (j);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}


void	*ft_calloc(size_t nitems, size_t size)
{
	void	*exit;

	exit = malloc(nitems * size);
	if (exit == NULL)
	{
		free(exit);
		return (NULL);
	}
	ft_bzero(exit, nitems * size);
	return (exit);
}

static int	ft_count_splits(char const *s, char c)
{
	int	count;
	int	bool_in_word;

	count = 0;
	bool_in_word = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (bool_in_word == 0)
			{
				count++;
				bool_in_word = 1;
			}
		}
		else
			bool_in_word = 0;
		s++;
	}
	return (count);
}

static int	ft_sub_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			break ;
		i++;
	}
	return (i);
}

static char	**ft_free_mem(char **result, int i)
{
	while (i >= 0)
	{
		free(result[i--]);
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		splits;
	int		i;
	int		len;
	char	**result;

	if (!s)
		return (NULL);
	splits = ft_count_splits(s, c);
	result = (char **)malloc((splits + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (i < splits)
	{
		while (*s == c)
			s++;
		len = ft_sub_len(s, c);
		result[i] = (char *)malloc((len + 1) * sizeof(char));
		if (!result[i])
			return (ft_free_mem(result, i));
		ft_strlcpy(result[i++], s, len + 1);
		s += len;
	}
	result[splits] = NULL;
	return (result);
}
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	char		*output;
	static int	line_count = -1;
	ssize_t		bytes_read;
	
	if (fd < 0)
		return (NULL);
	output = ft_calloc(1,1);
	while (!ft_is_nl(output) && !ft_is_end(output))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1) {
			free(output);
			return NULL;
		}
		buffer[bytes_read] = '\0'; // Ensure null termination
		output = ft_strjoin(output, buffer);
	}
	line_count++;
	return (ft_split(output, '\n')[line_count]);
	// return (output);
}

// int	main()
// {
// 	int	fd;

// 	fd = open("lorem.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error al leer el archivo");
// 		return (-1);
// 	}
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	printf("%s",get_next_line(fd));
// 	return 0;
// }
