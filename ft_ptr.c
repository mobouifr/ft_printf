/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:27:15 by mobouifr          #+#    #+#             */
/*   Updated: 2023/12/23 16:35:45 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(unsigned long nb)
{
	unsigned long	remainder;
	unsigned long	i;
	unsigned long	count;
	char			arr[20];

	i = 0;
	count = 0;
	if (nb == 0)
		return (ft_putstr("0x0"));
	while (nb > 0)
	{
		remainder = nb % 16;
		if (remainder < 10)
			arr[i++] = remainder + '0';
		else
			arr[i++] = remainder - 10 + 'a';
		nb = nb / 16;
		count++;
	}
	write(1, "0x", 2);
	while (i > 0)
		write(1, &arr[--i], 1);
	return (count + 2);
}
