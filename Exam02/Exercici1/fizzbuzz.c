#include <unistd.h>

void write_number(int i)
{
    char c;
    char u;
    char d;

    if (i < 10)
    {
        c = i + '0';
        write(1, &c, 1);
    }
    else if (i == 100)
        write(1, "100", 3);
    else
    {
        u = (i / 10) + '0';
        d = (i % 10) + '0';
        write(1, &u, 1);
        write(1, &d, 1);
    }
}

int main(void)
{
    int i;
    char c;

    i = 6;
    write(1, "1\n2\nfizz\n4\nbuzz\n", 16);
    while (i < 101)
    {
        c = i + '0';
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            write_number(i);
        write(1, "\n", 1);
        i++;
    }
}