#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	count_words(char *str)
{
	int w;
	int i;

	w = 0;
	i = 1;
	if (str[0] == '\0')
		return (0);
	if (str[0] != ' ' && str[0] != '\t' && str[0] != '\n')
		w++;
	while (str[i])
	{
		if ((str[i] != ' ' && str[i] != '\t' && str[i] != '\n') && (str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n'))
			w++;
		i++;
	}
	return (w);
}

int count_letters(char *str, int i)
{
	int cont;

	cont = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
	{
		cont++;
		i++;
	}
	return (cont);
}

char    **ft_split(char *str)
{
	char **split;
	int words;
	int i;
	int letters;
	int j;
	int k;

	i = 0;
	letters = 0;
	j = 0;
	k = 0;
	words = count_words(str);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (str[i])
	{
		letters = count_letters(str, i);
		if (letters != 0)
		{
			split[j] = (char *)malloc((letters + 1) * sizeof(char));
			if (!split)
				return (NULL);
			while (letters > 0)
			{
				split[j][k] = str[i];
				k++;
				i++;
				letters--;
			}
			split[j][k] = '\0';
			k = 0;
			j++;
		}
		else
			i++;
	}
	split[j] = NULL;
	return (split);
}

int main(void)
{
	char s[] = "i    Hola que tal i";
	int i = count_words(s);
	printf("%d\n", i);
	return (0);
}
