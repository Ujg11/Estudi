#include <unistd.h>
#include <stdio.h>

size_t  search(const char *accept, char c)
{
    size_t  i;
    size_t  bol;

    i = 0;
    bol = 1;
    while (accept[i])
    {
        if (accept[i] == c)
            return (bol);
        i++;
    }
    bol = 0;
    return (bol);
}

size_t	ft_strspn(const char *s, const char *accept)
{
    size_t  i;

    i = 0;
    while (s[i] && search(accept, s[i]) == 1)
        i++;
    return (i);
}

int main(void)
{
    char s[] = "Hello how are u";
    char accept[] = "Hhelo ";
    size_t i;

    i = ft_strspn(s, accept);
    printf("%d\n", i);
    return (0);
}