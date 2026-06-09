/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:08:45 by iualkhim          #+#    #+#             */
/*   Updated: 2026/06/09 16:26:16 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_hex_ptr(unsigned long nbr)
{
	char	*base;
	int		len;

	len = 0;
	if (nbr > 15)
		len += ft_putnbr_hex_ptr(nbr / 16);
	base = "0123456789abcdef";
	write(1, &base[nbr % 16], 1);
	len++;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		len = 5;
	}
	else
	{
		len = 0;
		write(1, "0x", 2);
		len += 2;
		len += ft_putnbr_hex_ptr((unsigned long)ptr);
	}
	return (len);
}
