/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyuki <minkyuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:42:17 by minkyuki          #+#    #+#             */
/*   Updated: 2022/11/11 09:01:01 by minkyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(long long n);

void	ft_putnbr_fd(int n, int fd)
{
	char		digit[11];
	long long	num;
	int			length;

	num = n;
	ft_bzero(digit, 11);
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	length = count_digit(num);
	while (length > 0)
	{
		digit[length - 1] = num % 10 + '0';
		num /= 10;
		length--;
	}
	ft_putstr_fd(digit, fd);
}

static int	count_digit(long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		cnt = 1;
	else if (n < 0)
	{
		cnt++;
		n *= -1;
	}
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}
