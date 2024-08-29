/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabbas <moabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:36:02 by moabbas           #+#    #+#             */
/*   Updated: 2024/07/04 10:25:48 by moabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	print_exit(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	exit(1);
}

int	open_file(char *filename, int o_flags)
{
	int	fd;

	fd = open(filename, o_flags);
	if (fd < 0)
		print_exit("");
	return (fd);
}

void	print_and_free(char *msg, t_map *map)
{
	ft_free(map);
	print_exit(msg);
}

void	print_and_close(char *msg, int fd)
{
	close(fd);
	print_exit(msg);
}

int	get_lines_count(char *filename)
{
	char	*line;
	int		lines_count;
	int		fd;

	lines_count = 0;
	fd = open_file(filename, O_RDONLY);
	line = get_next_line(fd);
	if (line)
		lines_count++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			lines_count++;
	}
	close(fd);
	return (lines_count);
}
