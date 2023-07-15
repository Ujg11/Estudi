#include <unistd.h>

void	ft_putnbr(int n)
{
	char c;
	int rest;

	if (n > 10)
		ft_putnbr(n / 10);
	rest = n % 10;
	c = rest + '0';
	write(1, &c, 1);
}

int main(int argc, char *argv[])
{
	(void)argv;

	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}