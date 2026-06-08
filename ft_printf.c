#include "ft_printf.h"

static int handle_specifier(char specifier, va_list args)
{
    if(specifier == 'c')
        return (ft_putchar(va_arg(args, int)));
    if(specifier == '%')
        return (ft_putchar('%'));
    if(specifier == 's')
        return (ft_putstr(va_arg(args, char *)));
    if(specifier == 'd' || specifier == 'i')
        return (ft_putnbr(va_arg(args, int)));
    if(specifier == 'u')
        return (ft_putnbr_u(va_arg(args, unsigned int)));
    if(specifier == 'x' || specifier == 'X')
        return (ft_putnbr_hex(va_arg(args, unsigned int), specifier));
    if(specifier == 'p')
        return (ft_putptr(va_arg(args, void *)));
    return (0);
}

int ft_printf(char const *str, ...)
{
    va_list args;
    va_start(args, str);
    size_t i;
    size_t len;
    
    i = 0;
    len = 0;
    while(str[i])
    {
        if(str[i] == '%')
        {
           len += handle_specifier(str[i + 1], args);
           i += 2;
        }
        else
        {
            len += write(1, &str[i], 1);
            i++; 
        }
    }
    return (len);
}