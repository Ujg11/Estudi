#include <unistd.h>

int main(int argc, char *argv[])
{
	char	*s;
	int		i;
	char	c;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	s = argv[1];
	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			write (1, "_", 1);
			c = s[i] + 32;
			write(1, &c, 1);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	return (0);
}