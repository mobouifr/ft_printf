/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouifr <mobouifr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:27:03 by mobouifr          #+#    #+#             */
/*   Updated: 2023/12/23 16:37:43 by mobouifr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <limits.h>

int	ft_ptr(unsigned long nb);
int	ft_putchar(char c);
int	ft_puthex(unsigned int nb);
int	ft_putnbr(int nb);
int	ft_putstr(char *s);
int	ft_putuphex(unsigned int nb);
int	ft_u_putnbr(unsigned int n);
int	ft_printf(const char *p, ...);
#endif
