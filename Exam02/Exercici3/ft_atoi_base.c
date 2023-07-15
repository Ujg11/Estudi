#include <unistd.h>
#include <stdio.h>
//base: 0123456789abcdef

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (c + ('a' - 'A'));
    return (c);
}

int get_digit(char c, int str_base)
{
    int max_digit;

    if (str_base <= 10)
        max_digit = str_base + '0';
    else
        max_digit = str_base - 10 + 'a';

    if (c >= '0' && c <= '9' && c <= max_digit)
        return (c - '0');
    else if (c >= 'a' && c <= 'f' && c <= max_digit)
        return (c + 10 - 'a');
    else
        return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int sign = 1;
    int digit;
    int i = 0;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while ((digit = get_digit(to_lower(str[i]), str_base)) >= 0)
    {
        result = result * str_base + digit;
        i++;
    }
    return (result * sign);
}

int main(void)
{
    int num;

    num = ft_atoi_base("12fdb3", 4);
    printf("%d\n", num);
    return (0);
}