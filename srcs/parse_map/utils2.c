/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:36:02 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 10:25:37 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_free(t_map *map)
{
	int	i;

	i = 0;
	while (map->lines[i])
	{
		free(map->lines[i]);
		i++;
	}
	free(map->lines);
	free(map);
}
