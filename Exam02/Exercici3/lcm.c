#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int n;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else if (a < b)
		n = b;
	else
		return (a);
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}

int main(void)
{
	unsigned int res;
	res = lcm(2, 2);
	printf("%d\n", res);
	return (0);
}