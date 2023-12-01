#include <unistd.h>
#include <stdarg.h>

int	print_string(char *s)
{
	int i;
	int	cont_char;

	i = 0;
	cont_char = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		cont_char += write(1, &s[i], 1);
		if (cont_char == -1)
			return (-1);
		i++;
	}
	return (cont_char);
}

void	print_number(long int n, int base_n, int *cont_char)
{
	char	b[] = "0123456789abcdef";

	if (n < 0)
	{
		n = -n;
		*cont_char += write(1, "-", 1);
	}
	if (n >= base_n)
		print_number((n / base_n), base_n, cont_char);
	*cont_char += write(1, &b[n % base_n], 1);
}

int	ft_printf(const char *str, ...)
{
	int		cont_char;
	va_list	args;
	char	*s;
	int		i;

	s = (char *)str;
	i = 0;
	va_start(args, str);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == 's')
				cont_char += print_string(va_arg(args, char *));
			else if (s[i + 1] == 'd')
				print_number((long int)va_arg(args, int), 10, &cont_char);
			else if (s[i + 1] == 'x')
				print_number((long int)va_arg(args, unsigned int), 16, &cont_char);
			else if (s[i + 1] == '%')
				cont_char += write (1, "%", 1);
			i++;
		}
		else
			cont_char += write(1, &s[i], 1);
		if (cont_char == -1)
			return (-1);
		i++;
	}
	return (cont_char);
}

int main (void)
{
	ft_printf("%s\n", "toto12");
	ft_printf("Magic %s is %d\n", "number", 42);
	ft_printf("Hexadecimal for %d is %x\n", 42, 42);
}