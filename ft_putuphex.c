/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuphex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:28:02 by mobouifr          #+#    #+#             */
/*   Updated: 2023/12/29 11:28:20 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuphex(unsigned int nb)
{
	unsigned int	remainder;
	unsigned int	i;
	unsigned int	count;
	char			arr[20];

	i = 0;
	count = 0;
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb > 0)
	{
		remainder = nb % 16;
		if (remainder < 10)
			arr[i++] = remainder + '0';
		else
			arr[i++] = remainder - 10 + 'A';
		nb = nb / 16;
	}
	while (i > 0)
	{
		write(1, &arr[--i], 1);
		count++;
	}
	return (count);
}
