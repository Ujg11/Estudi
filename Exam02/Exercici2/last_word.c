#include <unistd.h>

int main(int argc, char *argv[])
{
    char *s;
    int   i;

    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    s = argv[1];
    i = 0;
    while (s[i])
        i++;
    i--;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        i--;
    while (i >= 0 && s[i] != ' ' && s[i] != '\t')
        i--;
    i++;
    while (s[i] && s[i] != ' ' && s[i] != '\t')
    {
        write (1, &s[i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}