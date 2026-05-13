/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apinho-a <apinho-a@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 14:25:12 by apinho-a          #+#    #+#             */
/*   Updated: 2026/05/13 21:58:51 by apinho-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>


int	ft_putchar_fd(char c, int fd);
int	ft_putstr_fd(char *s, int fd);
int ft_putstr_invalid(char formatter, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int	ft_putnbr_hex(unsigned int n, int fd, char *hex);
int	ft_putnbr_hex_address(unsigned long long n, int fd, char *hex);

#endif