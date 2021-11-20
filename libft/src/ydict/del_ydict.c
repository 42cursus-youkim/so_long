/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ydict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:45:52 by youkim            #+#    #+#             */
/*   Updated: 2021/11/20 17:05:57 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_ydictitem(t_dictitem *item)
{
	del_ystr(item->key);
	del_ystr(item->value);
	free(item);
}

void	del_ydict(t_dict *dict)
{
	int	i;

	i = -1;
	while (++i < (int)dict->capacity)
		if (dict->items[i])
			del_ydictitem(dict->items[i]);
	free(dict->items);
	free(dict);
}