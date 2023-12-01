#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	print_string(char *str)
{
	int num_char;
	int i;

	i = 0;
	num_char = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		num_char += write(1, &str[i], 1);
		if (num_char == -1)
			return (-1);
		i++;
	}
	return (num_char);
}

void	print_digit(long int n, int base_n, int *num_char)
{
	char	base[] = "0123456789abcdef";

	if (n < 0)
	{
		n = -n;
		*num_char += write(1, "-", 1);
	}
	if (n >= base_n)
		print_digit((n / base_n), base_n, num_char);
	*num_char += write(1, &base[n % base_n], 1);
}

int	init_printf(va_list args, char *s)
{
	int	i;
	int	num_char;
	int	aux;

	i = 0;
	num_char = 0;
	aux = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 's')
			{
				aux = print_string(va_arg(args, char *));
				num_char = num_char + aux;
			}
			else if (s[i + 1] == 'd')
				print_digit((long int)va_arg(args, int), 10, &num_char);
			else if (s[i + 1] == 'x')
				print_digit((long int)va_arg(args, unsigned int), 16, &num_char);
			else if (s[i + 1] == '%')
				num_char += write(1, "%", 1);
			i++;
		}
		else
		{
			aux = write(1, &s[i], 1);
			num_char = num_char + aux;
		}
		if (num_char == -1)
				return (-1);
		i++;
	}
	return (num_char);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	*s;
	int		num_char;

	s = (char *)str;
	va_start(args, str);
	num_char = init_printf(args, s);
	va_end(args);
	return (num_char);
}

int main(void)
{
	int	i;

	i = ft_printf("%s\n", NULL);
	ft_printf("%d\n", i);
	/*i = printf("%s\n", "toto");
	printf("%d\n", i);
	i = printf("%d", 0);
	printf("\n%d", i);
	/*
	i = ft_printf("%d\n", 23);
	ft_printf("%d\n", i);
	i = ft_printf("%x\n", 42);
	ft_printf("%d\n", i);*/
	return (0);
}