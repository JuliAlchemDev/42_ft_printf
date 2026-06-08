#include "ft_printf.h"

int ft_putnbr_u(unsigned int nbr)
{
    int len;
    char num;

    len = 0;
    if(nbr > 9)
        len += ft_putnbr_u(nbr / 10);
    num = (nbr % 10) + '0';
    write(1, &num, 1);
    len++;
    return (len);
}