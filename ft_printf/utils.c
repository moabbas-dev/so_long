/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:40:49 by moabbas           #+#    #+#             */
/*   Updated: 2024/06/20 12:34:59 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_num_len(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

int	get_unsigned_num_len(unsigned int num)
{
	int	len;

	if (num == 0)
		return (0);
	len = 0;
	while (num > 0)
	{
		len++;
		num /= 10;
	}
	return (num);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*result;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	result = (char *)malloc(11);
	if (!result)
		return (NULL);
	i = 0;
	while (n > 0)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	result[i] = '\0';
	ft_strrev(result);
	return (result);
}
