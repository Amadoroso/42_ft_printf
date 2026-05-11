/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 17:14:04 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/11 20:54:12 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_formatter_check(char formatter, va_list args)
{

	if (formatter == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	if (formatter == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	if (formatter == 'p')
		
	if (formatter == 'd' || formatter == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (formatter == 'u')
		ft_putnbr_unsigned_fd(va_arg(args, unsigned int), 1);
	if (formatter == 'x')
		ft_putnbr_hex(va_arg(args, int), 1, "0123456789abcdef");
	if (formatter == 'X')
		ft_putnbr_hex(va_arg(args, int), 1, "0123456789ABCDEF");
	if (formatter == '%')
		ft_putchar_fd('%', 1);
	
}

static int	ft_arg_counter(const char *formatter)
{
	int	formatter_count;

	formatter_count = 0;
	while (*formatter)
	{
		if (*formatter == '%')
			formatter_count++;
		formatter++;
	}
	return (formatter_count);
}

int	ft_printf(const char *formatter, ...)
{
	int		formatter_count;
	va_list	args;

	va_start(args, formatter);
	formatter_count = ft_arg_counter(formatter);
	while (*formatter && formatter_count)
	{
		if (*formatter == '%' && *(formatter + 1) != 0)
		{
			formatter++;
			formatter_count--;
			ft_formatter_check(*formatter, args);
		}
		formatter++;
	}
	
	va_end(args);
	return (1);
}

int	main ()
{
	ft_printf("%d", 1);
}