#include <unistd.h>
#include <stdarg.h>

static int handle_specifier(char specifier, va_list args)
{
    if(specifier == 'c')
        return (ft_putchar(va_arg(args, int)));
    if(specifier == '%')
        return (ft_putchar('%'));
    if(specifier == 's')
        return (ft_putstr(va_arg(args, char *)));
    // TODO
    // if(specifier == 'd' || specifier == 'i')
    // if(specifier == 'u')
    // if(specifier == 'x' || specifier == 'X')
    // if(specifier == 'p')
    return (0);
}