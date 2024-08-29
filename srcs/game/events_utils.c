/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:49:59 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 13:30:40 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_collectiblles(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == COLLECTIBLE)
				count++;
		}
	}
	return (count);
}

void	handle_w_press(t_game *game)
{
	if (game->y_player == 1)
		return ;
	if (game->map[game->y_player - 1][game->x_player] == WALL)
		return ;
	if (game->map[game->y_player - 1][game->x_player] == COLLECTIBLE)
		game->collect_count--;
	if (game->map[game->y_player - 1][game->x_player] == EXIT)
	{
		if (game->collect_count > 0)
			return ;
		else if (game->collect_count == 0)
			(ft_printf("You Win!\n"), close_event(game));
	}
	game->map[game->y_player][game->x_player] = EMPTY;
	game->y_player--;
	game->map[game->y_player][game->x_player] = PLAYER;
	mlx_clear_window(game->mlx, game->win);
	put_images(game);
	game->num_move++;
	ft_printf("Number of mouvments:%d\n", game->num_move);
}

void	handle_s_press(t_game *game)
{
	if (game->y_player == game->height - 2)
		return ;
	if (game->map[game->y_player + 1][game->x_player] == WALL)
		return ;
	if (game->map[game->y_player + 1][game->x_player] == COLLECTIBLE)
		game->collect_count-- ;
	if (game->map[game->y_player + 1][game->x_player] == EXIT)
	{
		if (game->collect_count > 0)
			return ;
		else if (game->collect_count == 0)
			(ft_printf("You Win!\n"), close_event(game));
	}
	game->map[game->y_player][game->x_player] = EMPTY;
	game->y_player++;
	game->map[game->y_player][game->x_player] = PLAYER;
	mlx_clear_window(game->mlx, game->win);
	put_images(game);
	game->num_move++;
	ft_printf("Number of mouvments:%d\n", game->num_move);
}

void	handle_d_press(t_game *game)
{
	if (game->x_player == game->width - 2)
		return ;
	if (game->map[game->y_player][game->x_player + 1] == WALL)
		return ;
	if (game->map[game->y_player][game->x_player + 1] == COLLECTIBLE)
		game->collect_count--;
	if (game->map[game->y_player][game->x_player + 1] == EXIT)
	{
		if (game->collect_count > 0)
			return ;
		else if (game->collect_count == 0)
			(ft_printf("You Win!\n"), close_event(game));
	}
	game->map[game->y_player][game->x_player] = EMPTY;
	game->x_player++;
	game->map[game->y_player][game->x_player] = PLAYER;
	mlx_clear_window(game->mlx, game->win);
	put_images(game);
	game->num_move++;
	ft_printf("Number of movements:%d\n", game->num_move);
}

void	handle_a_press(t_game *game)
{
	if (game->x_player == 1)
		return ;
	if (game->map[game->y_player][game->x_player - 1] == WALL)
		return ;
	if (game->map[game->y_player][game->x_player - 1] == COLLECTIBLE)
		game->collect_count--;
	if (game->map[game->y_player][game->x_player - 1] == EXIT)
	{
		if (game->collect_count > 0)
			return ;
		else if (game->collect_count == 0)
			(ft_printf("You Win!\n"), close_event(game));
	}
	game->map[game->y_player][game->x_player] = EMPTY;
	game->x_player--;
	game->map[game->y_player][game->x_player] = PLAYER;
	mlx_clear_window(game->mlx, game->win);
	put_images(game);
	game->num_move++;
	ft_printf("Number of mouvments:%d\n", game->num_move);
}
