/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ystr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim < youkim@student.42seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 10:54:05 by youkim            #+#    #+#             */
/*   Updated: 2021/11/17 12:04:44 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ystring.h"

//same as free. hmmm....
void	del_ystr(char *str)
{
	free(str);
}