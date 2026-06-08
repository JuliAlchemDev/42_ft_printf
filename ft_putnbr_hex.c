#include "ft_printf.h"

int ft_putnbr_hex(unsigned int nbr, char format)
{
    char *base;
    int i; /* index */ 
    int len;

    len = 0;
    if (format == 'X')
        base = "0123456789ABCDEF";
    else 
        base = "0123456789abcdef"; 
    if(nbr > 15)
        len += ft_putnbr_hex(nbr / 16, format);
    i = nbr % 16;
    write(1, &base[i], 1);
    len++;
    return (len);
}