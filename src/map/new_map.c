/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 11:03:10 by youkim            #+#    #+#             */
/*   Updated: 2021/12/01 19:59:08 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**new_loadgrid(const char *file_name)
{
	int		fd;
	char	*line;
	char	*buffer;
	char	**grid;

	fd = ycheckerr(open(file_name, O_RDONLY), "invalid map name!!!");
	line = new_ystr("");
	while (true)
	{
		buffer = yreadline(fd);
		if (!buffer)
			break ;
		ystr_append(&line, buffer);
		del_ystr(buffer);
	}
	grid = new_ysplit(line, '\n');
	close(fd);
	del_ystrs((char *[]){line, buffer, NULL});
	return (grid);
}

static int	get_map_size(t_map *map)
{
	int		len;
	int		len_prev;
	t_vec	vec;

	len_prev = 0;
	vec_set(&vec, -1, -1);
	while (map->grid[++vec.y])
	{
		len = 0;
		vec.x = -1;
		while (map->grid[vec.y][++vec.x])
			++len;
		if (len_prev && len_prev != len)
			return (ERROR);
		len_prev = len;
	}
	size_assign(&map->size, &vec);
	return (SUCCESS);
}

t_map	*new_map(const char *map_name)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		yerror("init_map", "malloc error");
	map->grid = new_loadgrid(map_name);
	map->charmap = new_ycharmap(
			(char []){'0', '1', '\0'},
			(char *[]){"ground", "wall", NULL});
	yassert(get_map_size(map) == SUCCESS, "map is not rectangular!");
	set_map_size(map);
	yassert(valdidate_map_file(map) == SUCCESS, "invalid map!");
	// place_player(map);
	return (map);
}
