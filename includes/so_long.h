/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:35:36 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 13:32:08 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_PATH "/home/moabbas/core/so_long/images/"

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <math.h>
# include "../ft_printf/ft_printf.h"
# include "fcntl.h"

# define WALL '1'
# define EMPTY '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

/* TYPEDEFS */
typedef struct s_map
{
	char	**lines;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_backg;
	void	*img_collect;
	void	*img_player;
	void	*img_exit;
	int		x_player;
	int		y_player;
	int		width;
	int		height;
	int		num_move;
	int		collect_count;
	char	**map;
}	t_game;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_counts
{
	int	player_count;
	int	exit_count;
	int	collectible_count;
}	t_counts;

/* UTILS */
void	ft_free(t_map *map);
void	print_exit(char *msg);
void	print_and_close(char *msg, int fd);
void	print_and_free(char *msg, t_map *map);
void	print_exit(char *msg);
int		open_file(char *filename, int o_flags);
int		get_lines_count(char *filename);

/* PARSING */
void	check_counts(t_map *map, t_counts *counts);
void	check_walls(t_map *map);
void	dfs(t_map *map, int **visited, t_point *pos, t_counts *counts);
int		**fill_visited(t_map *map, t_counts *counts, t_point *start);
t_map	*parse_map(char *filename);

/* GAME */
void	copy_map(t_game *game, t_map *map);
void	init_game(t_game *game, t_map *map);
void	render_game(t_game *game);
void	load_images(t_game *game);
void	handle_events(t_game *game);
void	put_images_init(t_game *game, int i);
void	put_images(t_game *game);
int		get_collectiblles(t_game *game);

/* EVENTS */
void	handle_w_press(t_game *game);
void	handle_s_press(t_game *game);
void	handle_d_press(t_game *game);
void	handle_a_press(t_game *game);
int		close_event(void *param);
#endif