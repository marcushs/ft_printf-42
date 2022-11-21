/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:47:46 by hleung            #+#    #+#             */
/*   Updated: 2022/11/21 19:54:32 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *arg, ...)
{
	int		i;
	int		len;
	va_list	ptr;

	len = 0;
	i = 0;
	va_start(ptr, arg);
	while (arg[i])
	{
		if (arg[i] == '%' && arg[i + 1] == 'c')
		{
			len += ft_putchar((unsigned char)va_arg(ptr, int));
			i++;
		}
		else if (arg[i] == '%' && arg[i + 1] == 's')
		{
			len += ft_putstr(va_arg(ptr, char *));
			i++;
		}
		else if (arg[i] == '%' && (arg[i + 1] == 'd' || arg[i + 1] == 'i'))
		{
			len += ft_putnbr((unsigned int)va_arg(ptr, int));
			i++;
		}
		else if (arg[i] == '%' && arg[i + 1] == 'p')
		{
			ft_putstr("0x");
			len += ft_putadd((unsigned long)va_arg(ptr, void *), "abcdef") + 2;
			i++;
		}
		else if (arg[i] == '%' && arg[i + 1] == 'u')
		{
			len += ft_putnbr_unsigned(va_arg(ptr, unsigned int));
			i++;
		}
		else if (arg[i] == '%' && arg[i + 1] == 'x')
		{
			len += ft_putnbr_base(va_arg(ptr, int), "abcdef");
			i++;
		}
		else if (arg[i] == '%' && arg[i + 1] == 'X')
		{
			len += ft_putnbr_base(va_arg(ptr, int), "ABCDEF");
			i++;
		}
		else if (arg[i] == '%' && arg[i + 1] == '%')
		{
			len += ft_putchar('%');
			i++;
		}
		else
			len += ft_putchar(arg[i]);
		i++;
	}
	return (len);
	va_end(ptr);
}
