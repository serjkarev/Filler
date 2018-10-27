/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:59:02 by skarev            #+#    #+#             */
/*   Updated: 2018/10/17 16:59:03 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_lstmap(t_lstmap *lstmap)
{
	int		i;

	i = 0;
	while (lstmap->map[i])
	{
		free(lstmap->map[i]);
		i++;
	}
}

void	free_lstpiece(t_lstpiece *lstpiece)
{
	int		i;

	i = 0;
	while (lstpiece->piece[i])
	{
		free(lstpiece->piece[i]);
		i++;
	}
	free(lstpiece->piece);
}