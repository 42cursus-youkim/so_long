/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:05:13 by youkim            #+#    #+#             */
/*   Updated: 2021/12/03 11:49:05 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_frame(t_info *info)
{
	info->frames++;
	if (info->frames > FRAME_CYCLE)
		info->frames = 0;
}

//	check if the tile the entity's trying to go is smthn
bool	is_there(t_map *map, t_vec *pos, char thing)
{
	return (map->grid[pos->y][pos->x] == thing);
}

//	-1 is terminator because 0 is for KEY_A
bool	is_input(t_keycode input, t_keycode keys[])
{
	int	i;

	i = -1;
	while ((int)keys[++i] != -1)
		if (input == keys[i])
			return (true);
	return (false);
}
