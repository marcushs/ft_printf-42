/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:55:04 by hleung            #+#    #+#             */
/*   Updated: 2022/11/21 17:58:03 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadd(unsigned long nbr, char *charset)
{
	int	len;

	len = 0;
	if (nbr == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (nbr > 15)
		len += ft_putadd(nbr / 16, charset);
	if (nbr % 16 >= 10)
		len += ft_putchar(charset[nbr % 16 - 10]);
	else
		len += ft_putchar(nbr % 16 + '0');
	return (len);
}
