#include <unistd.h>

int find_in_1(int i, char c, char *s)
{
    if (i == 0)
        return (1);
    i--;
    while (i >= 0)
    {
        if (s[i] == c)
            return (0);
        i--;
    }
    return (1);
}

int find_in_2(char c, char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (c == s[i])
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char *argv[])
{
    char *s1;
    char *s2;
    int i;
    int bol;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    s1 = argv[1];
    s2 = argv[2];
    i  = 0;
    bol = 0;
    while (s1[i])
    {
        bol = find_in_1(i, s1[i], s1);
        if (bol == 1)
        {
            if (find_in_2(s1[i], s2) == 1)
                write(1, &s1[i], 1);
        }
        i++;
    }
    write(1, "\n", 1);
    return (0);
}