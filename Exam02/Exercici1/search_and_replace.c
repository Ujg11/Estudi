#include <unistd.h>

int main(int argc, char *argv[])
{
	int		i;
	char	*str;
	char	s;
	char	r;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	str = argv[1];
	s = argv[2][0];
	r = argv[3][0];
	i = 0;
	while (str[i])
	{
		if (str[i] == s)
			str[i] = r;
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}