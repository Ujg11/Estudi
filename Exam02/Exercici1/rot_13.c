#include <unistd.h>

int main(int argc, char *argv[])
{
    char *s;
    int i;
    char c;
    
    if (argc != 2)
    {
        write (1, "\n", 1);
        return (0);
    }
    s = argv[1];
    i = 0;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            c = (s[i] - 'a' + 13) % 26 + 'a';
        else if (s[i] >= 'A' && s[i] <= 'Z')
            c = (s[i] - 'A' + 13) % 26 + 'A';
        write(1, &c, 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}