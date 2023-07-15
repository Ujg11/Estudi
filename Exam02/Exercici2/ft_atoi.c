int	ft_atoi(const char *str)
{
    int res;
    int i;
    int neg;

    i = 0;
    res = 0;
    neg = 1;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' 
    || str[i] == '\f' || str[i] == '\r')
        i++;
    if (str[i] == '-')
    {
        neg = -1;
        i++;
    }
    if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + str[i] - '0';
        i++;
    }
    return(res * neg);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *str = "  \n\r+13454";
    int i;

    i = ft_atoi(str);
    printf("%d\n", i);
    i = atoi(str);
    printf("%d\n", i);
    return (0);
}*/