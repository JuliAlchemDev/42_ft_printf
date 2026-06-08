#include "ft_printf.h"

int ft_putnbr(int nbr)
{
    int len;
    char num;

    len = 0;
    if (nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
        return (11);
    }
    if (nbr < 0)
    {
        write(1, "-", 1);
        len++;
        nbr *= -1;
    }
    if(nbr > 9)
        len += ft_putnbr(nbr / 10);
    num = (nbr % 10) + '0';
    write(1, &num, 1);
    len++;
    return (len);
}