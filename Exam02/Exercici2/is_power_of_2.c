#include <unistd.h>
#include <stdio.h>

int	is_power_of_2(unsigned int n)
{
	int	residue;

	residue = 0;
	if (n == 0 || n == 1)
		return (0);
	while (n != 1 && residue == 0) 
	{
		residue = n % 2;
		n = n / 2;
		//if (residue != 0)
		//	return (0);
	}
	//return (1);
	return ((n == 1) ? 1 : 0);
}

int main(void)
{
	int i;

	i = is_power_of_2(16);
	printf("%d\n", i);
	return (0);
}