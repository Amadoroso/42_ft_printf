/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_aux2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 13:35:01 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/14 13:37:20 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*(s + len))
		len++;
	write(fd, s, len);
	return (len);
}

int	ft_putstr_invalid(char formatter, int fd)
{
	int		len;
	char	c;

	c = '%';
	len = 0;
	if (!formatter)
		return (len);
	write(fd, &c, 1);
	write(fd, &formatter, 1);
	return (2);
}
