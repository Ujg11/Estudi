#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int a;
	int b;
	int num;

	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	if (a > b)
		num = a;
	else if (b > a)
		num = b;
	else
	{
		printf("%d\n", a);
		return (0);
	}
	while (num > 0)
	{
		if (a % num == 0 && b % num == 0)
		{
			printf("%d\n", num);
			return (0);
		}
		num--;
	}
	printf("%d\n", num);
	return (0);
}