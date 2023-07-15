#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int f;
    int l;
    char o;
    int res;

    if (argc == 4)
    {
        res = 0;
        f = atoi(argv[1]); 
        l = atoi(argv[3]);
        o = argv[2][0];
        if (o == '+')
            res = f + l;
        else if (o == '-')
            res = f - l;
        else if (o == '*')
            res = f * l;
        else if (o == '/')
            res = f / l;
        else if (o == '%')
            res = f % l;
        printf("%d", res);
    }
    write(1, "\n", 1);
    return (0);
}