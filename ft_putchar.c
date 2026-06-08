#include "ft_printf.h"

int ft_putchar(char ch)
{
    return (write(1, &ch, 1));
}