/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:27:46 by mobouifr          #+#    #+#             */
/*   Updated: 2023/12/29 11:37:22 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	n_zero_min(int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	return (0);
}

int	ft_putnbr(int nb)
{
	int	i;
	int	arr[10];
	int	count;

	i = 0;
	count = 0;
	if (nb == 0 || nb == -2147483648)
		return (n_zero_min(nb));
	if (nb < 0 && nb != -2147483648)
	{
		write(1, "-", 1);
		nb = nb * (-1);
		count = 1;
	}
	while (nb > 0)
	{
		arr[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
		count++;
	}
	while (i > 0)
		write(1, &arr[--i], 1);
	return (count);
}
