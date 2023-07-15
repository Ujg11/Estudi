#include <unistd.h>

int ft_atoi(char *str)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void print_hexa(int n)
{
	char base[] = "0123456789abcdef";
	int rest;

	if (n >= 16)
		print_hexa(n / 16);
	rest = n % 16;
	write(1, &base[rest], 1);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	print_hexa(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}