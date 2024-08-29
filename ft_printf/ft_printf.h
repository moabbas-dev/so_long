/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:40:51 by moabbas           #+#    #+#             */
/*   Updated: 2024/06/20 10:44:44 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int		print_char(char c);
int		print_string(char *s);
int		print_decimal(int n);
int		print_pointer(void *p);
int		print_unsigned(unsigned int num);
int		print_hex(unsigned int num, char x_case);
char	*ft_unsigned_itoa(unsigned int n);
void	ft_strrev(char *str);
int		ft_printf(const char *format, ...);

#endif