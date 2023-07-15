int	max(int* tab, unsigned int len)
{
	int n_max;
	unsigned int i;

	i = 0;
	n_max = 0;
	while (i < len)
	{
		if (n_max < tab[i])
			n_max = tab[i];
		i++; 
	}
	return (n_max);
}