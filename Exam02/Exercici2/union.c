//Escribe un programa que tome dos cadenas y muestre, sin duplicados, los caracteres que aparecen en cualquiera de 
//las dos cadenas.
//La visualización se realizará en el orden en que los caracteres aparecen en la línea de comandos y estará seguida
//de un salto de línea (\n).

#include <unistd.h>

int ft_strchr(char *s, char c, int i)
{
    i--;
    while (i >= 0)
    {
        if (s[i] == c)
            return (0);
        i--;
    }
    return (1);
}

int ft_strchr_all(char *s, char c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    char *s1;
    char *s2;
    int i;
    int bol1;
    int bol2;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    s1 = argv[1];
    s2 = argv[2];
    i = 0;
    bol1 = 0;
    bol2 = 0;
    while (s1[i])
    {
        bol1 = ft_strchr(s1, s1[i], i);
        if (bol1 == 1)
            write(1, &s1[i], 1);
        i++;
    }
    i = 0;
    while (s2[i])
    {
        bol1 = ft_strchr_all(s1, s2[i]);
        bol2 = ft_strchr(s2, s2[i], i);
        if (bol1 == 1 && bol2 == 1)
        {
            if(s1[i] != s2[i])
                write(1, &s2[i], 1);
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}