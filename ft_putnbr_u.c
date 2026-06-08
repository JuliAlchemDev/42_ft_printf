/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iualkhim <iualkhim@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 19:04:24 by iualkhim          #+#    #+#             */
/*   Updated: 2026/06/08 19:05:07 by iualkhim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int nbr)
{
	int		len;
	char	num;

	len = 0;
	if (nbr > 9)
		len += ft_putnbr_u(nbr / 10);
	num = (nbr % 10) + '0';
	write(1, &num, 1);
	len++;
	return (len);
}
