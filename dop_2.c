/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 16:29:58 by skarev            #+#    #+#             */
/*   Updated: 2018/10/31 16:29:58 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	helper_1(t_lstpiece *lstpiece, int i, int j, int tmp)
{
	lstpiece->manhattan = tmp;
	lstpiece->ret_x = j;
	lstpiece->ret_y = i;
}

void	helper_2(t_lstpiece *lstpiece, int i, int j, int tmp)
{
	tmp = lstpiece->manh;
	lstpiece->ret_x = j;
	lstpiece->ret_y = i;
}
