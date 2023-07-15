#include <unistd.h>
#include <stdlib.h>

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int     *ft_range(int start, int end)
{
	int i;
	int len;
	int *res; 
	
	i = 0;
	len = ft_abs(end - start) + 1;
	res = (int *)malloc(len * sizeof(int));
	while (i < len)
	{
		if (start < end)
		{
			res[i] = start;
			start++;
			i++;
		}
		else
		{
			res[i] = start;
			start--;
			i++;
		}
	}
	return (res);
}