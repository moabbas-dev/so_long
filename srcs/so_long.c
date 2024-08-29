/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:35:59 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 10:25:33 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#define WIN_WIDTH 600
#define WIN_HEIGHT 300

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		print_exit("Usage: ./so_long *.ber");
	map = parse_map(argv[1]);
	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		print_and_free("", map);
	init_game(game, map);
	render_game(game);
	handle_events(game);
	mlx_loop(game->mlx);
	ft_free(map);
	return (0);
}
