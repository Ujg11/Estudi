#include <unistd.h>

int ft_atoi(char *s)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (s[i])
    {
        res = (res * 10) + s[i] - '0';
        i++;
    }
    return (res);
}

int is_prime(int n)
{
    int i;

    if (n <= 1)
        return (0);
    i = n - 1;
    while (i > 1)
    {
        if (n % i == 0)
            return (0);
        i--;
    }
    return (1);
}

void ft_putnbr(int n)
{
    int res;
    char c;

    if (n >= 10)
        ft_putnbr(n / 10);
    res = n % 10;
    c = res + '0';
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    if (argc != 2 || argv[1][0] == '-')
    {
        write(1, "0\n", 2);
        return (0);
    }
    int num;
    int res;
    int bol;

    res = 0;
    bol = 0;
    num = ft_atoi(argv[1]);
    while (num > 1)
    {
            bol = is_prime(num);
            if (bol == 1)
                res = res + num;
            num--;
    }
    ft_putnbr(res);
    write(1, "\n", 1);
    return (0);
}