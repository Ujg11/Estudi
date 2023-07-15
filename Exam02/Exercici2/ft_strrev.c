#include <stdio.h>

char	*ft_strrev(char *str)
{
	int i;
	int len;
	char temp;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
	return (str);
}

int main(void)
{
	char str[] = "Hola";
	char *rev;

	rev = ft_strrev(str);
	printf("%s\n", rev);
	return (0);
}