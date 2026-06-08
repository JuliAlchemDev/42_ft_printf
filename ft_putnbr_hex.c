/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:06:05 by iualkhim          #+#    #+#             */
/*   Updated: 2026/06/08 19:08:11 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nbr, char format)
{
	char	*base;
	int		i;
	int		len;

	len = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
		len += ft_putnbr_hex(nbr / 16, format);
	i = nbr % 16;
	write(1, &base[i], 1);
	len++;
	return (len);
}
