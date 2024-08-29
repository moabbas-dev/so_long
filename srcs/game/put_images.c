/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:35:44 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 12:35:17 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	*put_img(t_game *game, int i, int j)
{
	void	*img;

	if (game->map[i][j] == WALL)
		img = game->img_wall;
	else if (game->map[i][j] == PLAYER)
	{
		img = game->img_player;
		game->x_player = j;
		game->y_player = i;
	}
	else if (game->map[i][j] == EMPTY)
		img = game->img_backg;
	else if (game->map[i][j] == COLLECTIBLE)
	{
		img = game->img_collect;
		game->collect_count++;
	}		
	else
		img = game->img_exit;
	return (img);
}

void	put_images_init(t_game *game, int i)
{
	void	*img;
	int		j;

	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			img = put_img(game, i, j);
			mlx_put_image_to_window(game->mlx, game->win, img,
				70 * j, 70 * i);
		}
	}
}

void	put_img_to_win(t_game *game, void *img, int i, int j)
{
	mlx_put_image_to_window(game->mlx, game->win, img,
		j * 70, i * 70);
}

void	put_images(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
			if (game->map[i][j] == EMPTY)
				mlx_put_image_to_window(game->mlx, game->win, game->img_backg,
					j * 70, i * 70);
		else if (game->map[i][j] == WALL)
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall,
				j * 70, i * 70);
		else if (game->map[i][j] == COLLECTIBLE)
			mlx_put_image_to_window(game->mlx, game->win, game->img_collect,
				j * 70, i * 70);
		else if (game->map[i][j] == PLAYER)
			mlx_put_image_to_window(game->mlx, game->win, game->img_player,
				j * 70, i * 70);
		else if (game->map[i][j] == EXIT)
			mlx_put_image_to_window(game->mlx, game->win, game->img_exit,
				j * 70, i * 70);
	}
}
