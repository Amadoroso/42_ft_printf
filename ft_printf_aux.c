/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:51:42 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/14 13:38:43 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = ft_putstr_fd("-2147483648", 1);
		return (count);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		count++;
	}
	if (n > 9)
		count += ft_putnbr_fd ((n / 10), fd);
	count += ft_putchar_fd((n % 10) + 48, fd);
	return (count);
}

int	ft_putnbr_hex(unsigned int n, int fd, char choice)
{
	char	*hex;
	int		count;

	if (choice == 'h')
		hex = "0123456789abcdef";
	else if (choice == 'H')
		hex = "0123456789ABCDEF";
	count = 0;
	if (n > 16)
		count += ft_putnbr_hex((n / 16), fd, hex);
	count += ft_putchar_fd(hex[n % 16], fd);
	return (count);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr_unsigned_fd((n / 10), fd);
	count += ft_putchar_fd((n % 10) + 48, fd);
	return (count);
}

int	ft_putnbr_hex_address(unsigned long long n, int fd, char *hex)
{
	int	count;

	count = 0;
	if (n > 16)
		count += ft_putnbr_hex_address((n / 16), fd, hex);
	count += ft_putchar_fd(hex[n % 16], fd);
	return (count);
}
