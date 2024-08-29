/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:44:13 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 10:34:04 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_counts(t_map *map, t_counts *counts)
{
	if (counts->player_count != 1)
		print_and_free("Invalid number of 'P'", map);
	if (counts->collectible_count < 1)
		print_and_free("Invalid number of 'C'", map);
	if (counts->exit_count != 1)
		print_and_free("Invalid number of 'E'", map);
}

void	check_walls(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->width)
		if (map->lines[0][i] != WALL || map->lines[map->height - 1][i] != WALL)
			print_and_free("Map is not closed by walls", map);
	i = -1;
	while (++i < map->height)
		if (map->lines[i][0] != WALL || map->lines[i][map->width - 1] != WALL)
			print_and_free("Map is not closed by walls", map);
}

int	valid_move(t_map *map, int **visited, t_point *s)
{
	return (s->x >= 0 && s->x < map->width && s->y >= 0 && s->y < map->height
		&& map->lines[s->y][s->x] != WALL && !visited[s->y][s->x]);
}

void	dfs(t_map *map, int **visited, t_point *pos, t_counts *counts)
{
	if (!valid_move(map, visited, pos))
		return ;
	visited[pos->y][pos->x] = 1;
	if (map->lines[pos->y][pos->x] == 'C')
		counts->collectible_count--;
	if (map->lines[pos->y][pos->x] == 'E')
	{
		counts->exit_count = 1;
		return ;
	}
	dfs(map, visited, &(t_point){pos->x + 1, pos->y}, counts);
	dfs(map, visited, &(t_point){pos->x - 1, pos->y}, counts);
	dfs(map, visited, &(t_point){pos->x, pos->y + 1}, counts);
	dfs(map, visited, &(t_point){pos->x, pos->y - 1}, counts);
}

int	**fill_visited(t_map *map, t_counts *counts, t_point *start)
{
	int	**visited;
	int	i;
	int	j;

	visited = (int **)malloc(sizeof(int *) * map->height);
	if (!visited)
		print_and_free("", map);
	i = -1;
	while (++i < map->height)
	{
		visited[i] = (int *)malloc(sizeof(int) * map->width);
		j = -1;
		while (++j < map->width)
		{
			visited[i][j] = 0;
			if (map->lines[i][j] == PLAYER)
			{
				start->x = j;
				start->y = i;
			}
			else if (map->lines[i][j] == COLLECTIBLE)
				counts->collectible_count++;
		}
	}
	return (visited);
}
