/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:01:21 by iualkhim          #+#    #+#             */
/*   Updated: 2026/06/08 19:03:26 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	int		len;
	char	num;

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
	if (nbr > 9)
		len += ft_putnbr(nbr / 10);
	num = (nbr % 10) + '0';
	write(1, &num, 1);
	len++;
	return (len);
}
