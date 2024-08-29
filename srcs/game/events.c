/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:25:39 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 11:50:43 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	close_event(void *param)
{
	t_game	*game;
	int		i;

	game = (t_game *)param;
	mlx_destroy_image(game->mlx, game->img_backg);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game);
	exit(0);
}

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == XK_Escape)
	{
		close_event(game);
		exit(0);
	}
	game->collect_count = get_collectiblles(game);
	if (keycode == XK_w)
		handle_w_press(game);
	if (keycode == XK_s)
		handle_s_press(game);
	if (keycode == XK_d)
		handle_d_press(game);
	if (keycode == XK_a)
		handle_a_press(game);
	return (0);
}

void	handle_events(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 33, 1L << 5, close_event, game);
}
