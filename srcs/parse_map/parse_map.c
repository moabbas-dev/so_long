/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:31:21 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 10:25:43 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_name(char *filename)
{
	char	*extension;
	int		fd;
	int		len;

	len = ft_strlen(filename);
	if (len <= 4)
		print_exit("The file should must be in format *.ber");
	if (len >= 5 && filename[ft_strlen(filename) - 5] == '/')
		print_exit("Bad File format");
	if (len >= 4)
	{
		extension = ft_substr(filename, len - 4, 4);
		if (ft_strncmp(extension, ".ber", 5) != 0)
		{
			free(extension);
			print_exit("The file should must be in format *.ber");
		}
		free(extension);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_exit("The file doesnt exist");
	close(fd);
}

void	check_lens(t_map *map)
{
	int		lines_count;
	int		line_len;
	int		i;

	lines_count = 0;
	line_len = ft_strlen(map->lines[0]);
	i = -1;
	while (map->lines[++i])
	{
		if ((int)ft_strlen(map->lines[i]) != line_len)
			print_and_free("The map is not rectangular", map);
		lines_count++;
	}
	if (lines_count < 3)
		print_and_free("The map is too little", map);
	map->width = line_len;
	map->height = lines_count;
}

void	check_valid_path(t_map *map)
{
	int			**visited;
	t_counts	counts;
	t_point		start;
	int			i;

	start = (t_point){-1, -1};
	counts = (t_counts){0, 0, 0};
	visited = fill_visited(map, &counts, &start);
	if (start.x == -1 || start.y == -1)
		print_and_free("No starting position found", map);
	dfs(map, visited, &start, &counts);
	i = -1;
	while (++i < map->height)
		free(visited[i]);
	free(visited);
	if (counts.collectible_count > 0 || !counts.exit_count)
		print_and_free("Not a valid path to complete the game", map);
}

void	check_map(t_map *map)
{
	t_counts	counts;
	int			i;
	int			j;

	counts = (t_counts){0, 0, 0};
	i = 0;
	while (i < map->height)
	{
		j = -1;
		while (++j < map->width)
			if (map->lines[i][j] == PLAYER)
				counts.player_count++;
		else if (map->lines[i][j] == EXIT)
			counts.exit_count++;
		else if (map->lines[i][j] == COLLECTIBLE)
			counts.collectible_count++;
		else if (map->lines[i][j] != WALL && map->lines[i][j] != EMPTY)
			print_and_free("Invalid character in the map", map);
		i++;
	}
	check_counts(map, &counts);
	check_walls(map);
	check_valid_path(map);
}

t_map	*parse_map(char *filename)
{
	t_map	*map;
	char	*line;
	int		fd;
	int		i;

	check_name(filename);
	map = (t_map *)malloc(sizeof(t_map));
	map->lines
		= (char **)malloc(sizeof(char *) * (get_lines_count(filename) + 1));
	fd = open_file(filename, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (ft_strchr(line, '\n'))
			map->lines[i++] = ft_substr(line, 0, ft_strlen(line) - 1);
		else
			map->lines[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	map->lines[i] = NULL;
	close(fd);
	(check_lens(map), check_map(map));
	return (map);
}
