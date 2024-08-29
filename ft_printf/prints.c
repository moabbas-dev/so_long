/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:40:43 by moabbas           #+#    #+#             */
/*   Updated: 2024/06/20 12:35:47 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_string(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

int	print_decimal(int n)
{
	char	*str_num;
	int		len;

	str_num = ft_itoa(n);
	if (!str_num)
		return (0);
	len = ft_strlen(str_num);
	ft_putstr_fd(str_num, 1);
	free(str_num);
	return (len);
}

void	put_pointer(unsigned long long num, int *len)
{
	if (num >= 16)
	{
		put_pointer(num / 16, len);
		put_pointer(num % 16, len);
	}
	else
	{
		if (num <= 9)
			*len += print_char(num + '0');
		else
			*len += print_char(num - 10 + 'a');
	}
}

int	print_pointer(void *p)
{
	unsigned long long	n;
	int					len;

	n = (unsigned long long)p;
	len = 0;
	if (n == 0)
		return (write(1, "(nil)", 5));
	len += write(1, "0x", 2);
	put_pointer(n, &len);
	return (len);
}
