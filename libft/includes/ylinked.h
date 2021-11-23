/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ylinked.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 09:22:56 by youkim            #+#    #+#             */
/*   Updated: 2021/11/23 17:56:09 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YLINKED_H
# define YLINKED_H

typedef struct s_dequenode
{
	int					num;
	struct s_dequenode	*left;
	struct s_dequenode	*right;
}	t_dequenode;

typedef struct s_deque
{
	int			size;
	t_dequenode	*head;
	t_dequenode	*tail;
}	t_deque;

// ===== @Functions =====
/*
** < new_ydeque.c > */

t_dequenode		*new_ydequenode(int num);
#endif