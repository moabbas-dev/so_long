/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:40:47 by moabbas           #+#    #+#             */
/*   Updated: 2024/06/20 12:35:53 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_hex(unsigned int num, char x_case, int *len)
{
	if (num >= 16)
	{
		put_hex(num / 16, x_case, len);
		put_hex(num % 16, x_case, len);
	}
	else
	{
		if (num <= 9)
			*len += print_char(num + '0');
		else
		{
			if (x_case == 'x')
			{
				*len += print_char(num - 10 + 'a');
			}
			else if (x_case == 'X')
				*len += print_char(num - 10 + 'A');
		}
	}
}

int	print_hex(unsigned int num, char x_case)
{
	int	len;

	len = 0;
	if (num == 0)
		return (write(1, "0", 1));
	put_hex(num, x_case, &len);
	return (len);
}

void	ft_strrev(char *str)
{
	char	tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int	print_unsigned(unsigned int num)
{
	char			*str;
	unsigned int	n;
	int				len;

	n = (unsigned int)num;
	str = ft_unsigned_itoa(n);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
