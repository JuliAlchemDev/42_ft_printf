#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int ft_printf(char const *str, ...);
int ft_putchar(char ch);
int ft_putstr(char *str);
int ft_putnbr(int nbr);
int ft_putnbr_u(unsigned int nbr);
int ft_putnbr_hex(unsigned int nbr, char format);
int ft_putptr(void *ptr);

#endif