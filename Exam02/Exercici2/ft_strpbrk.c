//La función strpbrk es una función en C que se utiliza para encontrar la primera aparición en una cadena de 
//cualquier carácter de un conjunto especificado. "strpbrk" significa "string pointer break" (punto de ruptura del 
//puntero de cadena). Busca la primera aparición en la cadena s1 de cualquier carácter presente en la cadena s2.

char	*ft_strpbrk(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                return ((char *)(s1 + i));
            j++;
        }
        i++;
    }
    return (0);
}