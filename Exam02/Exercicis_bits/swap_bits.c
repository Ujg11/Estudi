#include <stdio.h>
#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	//return (octet >> 4 | octet << 4);
	return (octet << 4 | octet >> 4);
}

/*void	print_bits(unsigned char octet)
{
	unsigned char bit;
	int i;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int main(void)
{
	unsigned char octet = 234;
	unsigned char resultat;

	resultat = swap_bits(octet);
	print_bits(octet);
	write(1, "\n", 1);
	print_bits(resultat);
	return (0);
}*/