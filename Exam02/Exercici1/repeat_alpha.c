#include <unistd.h>

int search_lett(char *s, char c)
{
    int i;

    i = 0;
    while (s[i] != '\0' && s[i] != c)
        i++;
    if (s[i] == c)
        return (i + 1);
    return(0);
}

int main(int argc, char *argv[])
{
    char *str;
    int lett;
    int i;
    int w;
    char c;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    i = 0;
    str = argv[1];
    while (str[i] != '\0')
    {
        lett = search_lett("abcdefghijklmnopqrstuvwxyz", str[i]);
        if (lett == 0)
            lett = search_lett("ABCDEFGHIJKLMNOPQRSTUVWXYZ", str[i]);
        w = 0;
        while (w < lett)
        {
            c = str[i];
            write(1, &c, 1);
            w++;
        }
        i++;
    }
    return (0);
}
