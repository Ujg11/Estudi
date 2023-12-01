#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (str + i);
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, const char *src, int l)
{
	int i;
	int	len;
	
	if (dst == NULL || src == NULL || l == 0)
        return 0;
		i = 0;
	len = ft_strlen((char *)src);
	if (l > 0)
	{
		while (i < len && i < l - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		len;

	len = ft_strlen((char *)src) + 1;
	dst = malloc(len * sizeof(char));
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, src, len);
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	int		len_s1;
	int		len_s2;
	char	*str_join;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = len;
	str_join = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!str_join)
		return (NULL);
	ft_strlcpy(str_join, s1, len_s1 + 1);
	ft_strlcpy((str_join + len_s1), s2, len_s2 + 1);
	free(s1);
	return (str_join);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	char		*newline;
	int			num_read;
	int			to_copy;

	line = ft_strdup(buf);
	num_read = 1;
	while (!(ft_strchr(line, '\n')) && num_read > 0)
	{
		num_read = read(fd, buf, BUFFER_SIZE);
		buf[num_read] = '\0';
		line = ft_strjoin(line, buf, num_read);
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	newline = ft_strchr(line, '\n');
	if (newline)
	{
		to_copy = newline - line + 1;//Obtenemos la cantidad de char que hay entre el principio de line y el '\n' y anyadimos 1
		ft_strlcpy(buf, newline + 1, BUFFER_SIZE + 1);
	}
	else 
	{
		to_copy = ft_strlen(line);
		ft_strlcpy(buf, "", BUFFER_SIZE + 1);
	}
	line[to_copy] = '\0';
	return (line);
}

int main(void)
{
    int fd;
    char *line;

    fd = open("prova.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }
    int ret;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Línea leída: %s\n", line);
        free(line);  // Recuerda liberar la memoria asignada por get_next_line
    }
    close(fd);

    return EXIT_SUCCESS;
}
