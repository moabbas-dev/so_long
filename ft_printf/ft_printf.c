/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:40:45 by moabbas           #+#    #+#             */
/*   Updated: 2024/06/20 13:29:25 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	analysis(char c, va_list args);
int	forward(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	if (!format)
		return (-1);
	va_start(args, format);
	len = forward(format, args);
	va_end(args);
	return (len);
}

int	analysis(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'd')
		return (print_decimal(va_arg(args, int)));
	else if (c == 'p')
		return (print_pointer(va_arg(args, void *)));
	else if (c == 'i')
		return (print_decimal(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsigned(va_arg(args, int)));
	else if (c == 'x')
		return (print_hex(va_arg(args, int), 'x'));
	else if (c == 'X')
		return (print_hex(va_arg(args, int), 'X'));
	else if (c == '%')
		return (write(1, &c, 1));
	return (0);
}

int	forward(const char *format, va_list args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			len += analysis(format[i + 1], args);
			i++;
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	return (len);
}
