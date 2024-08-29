/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:25:34 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 11:48:54 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game(t_game *game, t_map *map)
{
	game->mlx = mlx_init();
	game->win
		= mlx_new_window(game->mlx,
			map->width * 70, map->height * 70, "./so_long");
	copy_map(game, map);
	game->width = map->width;
	game->height = map->height;
	ft_free(map);
	game->collect_count = 0;
	game->num_move = 0;
}

void	*load_img(void *mlx_ptr, char *filename)
{
	char	*path;
	int		img_width;
	int		img_height;
	void	*img;

	img = NULL;
	path = ft_strjoin(IMG_PATH, filename);
	img = mlx_xpm_file_to_image(mlx_ptr, path, &img_width, &img_height);
	free(path);
	return (img);
}

void	load_images(t_game *game)
{
	game->img_backg = load_img(game->mlx, "backg.xpm");
	game->img_collect = load_img(game->mlx, "collectible.xpm");
	game->img_exit = load_img(game->mlx, "exit.xpm");
	game->img_player = load_img(game->mlx, "player.xpm");
	game->img_wall = load_img(game->mlx, "wall.xpm");
	if (!game->img_backg || !game->img_collect || !game->img_exit
		|| !game->img_player || !game->img_wall)
	{
		mlx_destroy_window(game->mlx, game->win);
		free(game);
		print_exit("Load Images Failed!");
	}
}

void	render_game(t_game *game)
{
	load_images(game);
	put_images_init(game, -1);
}

void	copy_map(t_game *game, t_map *map)
{
	int	i;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	while (map->lines[i])
	{
		game->map[i] = ft_strdup(map->lines[i]);
		i++;
	}
	game->map[i] = NULL;
}
