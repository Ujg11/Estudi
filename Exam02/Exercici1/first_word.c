#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    char c;

    i = 0;
    if (argc > 1)
    {
        while (argv[1][i] != '\0')
        {
            c = argv[1][i];
            write(1, &c, 1);
            i++;
        }
    }
    return (0);
}