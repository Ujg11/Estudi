#include <unistd.h>

void	replace(char c, char *alph)
{
	int i;

	i = 0;
	while (alph[i] != c)
		i++;
	if (i <= 12)
		write(1, &alph[25 - i], 1);
	else if (i > 12)
		write(1, &alph[(i - 25) * -1], 1);
}

int main(int argc, char *argv[])
{
	char	*s;
	int		i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	s = argv[1];
	i = 0;
	while(s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			replace(s[i], "abcdefghijklmnopqrstuvwxyz");
		else if(s[i] >= 'A' && s[i] <= 'Z')
			replace(s[i], "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		else
			write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}