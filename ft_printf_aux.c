/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:51:42 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/11 20:48:55 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	len;

	if (!s)
		return ;
	len = 0;
	while (*(s + len))
		len++;
	write(fd, s, len);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd ((n / 10), fd);
	ft_putchar_fd((n % 10) + 48, fd);
}

void	ft_putnbr_hex(int n, int fd, char *hex)
{	
	if (n == -2147483648)
	{
		ft_putstr_fd("-80000000", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n > 16)
		ft_putnbr_hex((n / 16), fd, hex);
	ft_putchar_fd(hex[n % 16], fd);
}

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd ((n / 10), fd);
	ft_putchar_fd((n % 10) + 48, fd);
}
/* int	main()
{
	ft_putnbr_hex(2147483647, 1, "0123456789abcdef");
} */

/* int main()
{
	ft_putnbr_unsigned_fd(4294967295, 1);
} */
