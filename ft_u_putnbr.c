/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:28:19 by mobouifr          #+#    #+#             */
/*   Updated: 2023/12/29 11:32:42 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u_putnbr(unsigned int n)
{
	unsigned int	remainder;
	unsigned int	i;
	char			arr[11];
	unsigned int	count;

	i = 0;
	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (n > 0)
	{
		remainder = n % 10;
		if (remainder < 10)
			arr[i++] = remainder + '0';
		n = n / 10;
	}
	while (i > 0)
	{
		write(1, &arr[--i], 1);
		count++;
	}
	return (count);
}
