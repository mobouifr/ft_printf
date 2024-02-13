/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:39:28 by mobouifr          #+#    #+#             */
/*   Updated: 2023/12/29 00:56:51 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	idu_case(const char *p, va_list args, int i)
{
	int	count;

	count = 0;
	if (p[i + 1] == 'i' || p[i + 1] == 'd')
	{
		count += ft_putnbr(va_arg(args, int));
	}
	else if (p[i + 1] == 'u')
	{
		count += ft_u_putnbr(va_arg(args, unsigned int));
	}
	return (count);
}

static int	xxp_case(const char *p, va_list args, int i)
{
	int	count;

	count = 0;
	if (p[i + 1] == 'x')
	{
		count += ft_puthex(va_arg(args, unsigned int));
	}
	else if (p[i + 1] == 'X')
	{
		count += ft_putuphex(va_arg(args, unsigned int));
	}
	else if (p[i + 1] == 'p')
	{
		count += ft_ptr(va_arg(args, unsigned long));
	}
	return (count);
}

static int	sc_case(const char *p, va_list args, int i)
{
	int	count;

	count = 0;
	if (p[i + 1] == 'c')
	{
		count += ft_putchar(va_arg(args, int));
	}
	else if (p[i + 1] == 's')
	{
		count += ft_putstr(va_arg(args, char *));
	}
	else if (p[i + 1] == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (count);
}

static int	n_case(const char *p, int i)
{
	int	count;

	count = 0;
	if (p[i + 1] != 's' && p[i + 1] != 'c'
		&& p[i + 1] != 'p' && p[i + 1] != 'd'
		&& p[i + 1] != 'i' && p[i + 1] != 'u'
		&& p[i + 1] != 'x' && p[i + 1] != 'X'
		&& p[i + 1] != '%')
	{
		count += ft_putchar(p[i + 1]);
	}
	return (count);
}

int	ft_printf(const char *p, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, p);
	i = 0;
	count = 0;
	while (p[i] != '\0')
	{
		if (p[i] == '%')
		{
			if (p[i + 1] == '\0')
				break ;
			count += sc_case(p, args, i);
			count += idu_case(p, args, i);
			count += xxp_case(p, args, i);
			count += n_case(p, i);
			i++;
		}
		else
			count += ft_putchar(p[i]);
		i++;
	}
	va_end(args);
	return (count);
}
/*int	main(void)
   {
   	ft_printf("%", ft_printf("%"));
   	printf("\n");
   	printf("%", printf("%"));
   	return (0);
   }*/
