#include <stdlib.h>

char    *ft_strdup(char *src)
{
    int i;
    char *dup;

    i = 0;
    while (src[i])
        i++;
    dup = (char *)malloc((i + 1) * sizeof(char));
    if (!dup)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (0);
}