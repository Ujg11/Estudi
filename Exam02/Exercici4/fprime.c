#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int num;
	int i;
	
	if (argc == 2)
	{
		i = 2;
		num = atoi(argv[1]);
		if (num == 1)
			printf("1");
		while (num >= i)
		{
			if (num % i == 0)
			{
				printf("%d", i);
				if (num == i)
					break;
				printf("*");
				num = num / i;
				i = 1;
			}
			i++;
		}
	}
	printf("\n");
}