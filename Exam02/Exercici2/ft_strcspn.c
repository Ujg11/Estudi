//La función strcspn es una función en C que se utiliza para determinar la longitud del segmento inicial de una 
//cadena que no contiene ningún carácter de un conjunto especificado. "strcspn" significa "string complement-span" 
//(extensión de cadena complementaria).

#include <unistd.h>
#include <stdio.h>

size_t	search(const char *reject, char c)
{
	size_t i;

	i = 0;
	while (reject[i] && reject[i] != c)
		i++;
	return (reject[i] - c);
}

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	while(s[i] && search(reject, s[i]) != 0)
		i++;
	return (i);
}
/*
int main(void)
{
	char *s = "Hola! que tal!!!";
	char *reject = "!";
	size_t num;

	num = ft_strcspn(s, reject);
	printf("%d\n", num);
	return (0);
}*/