#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
    int i;
    unsigned char rev_octet;

    i = 8;
    rev_octet = 0;
    while (i > 0)
    {
        rev_octet = rev_octet * 2 + (octet % 2);
        octet = octet / 2;
        i--;
    }
    return (rev_octet);
}

int main(void)
{
    unsigned char number = 170;
    
    printf("Num original: %d\n", number);
    printf("Num invertit: %d\n", reverse_bits(number));
    return (0);
}
