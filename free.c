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

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int		print_coords(t_lstpiece *lstpiece)
{
	if (lstpiece->ret_x == 0 && lstpiece->ret_y == 0)
	{
		write(1, "0 0", 3);
		return (0);
	}
	ft_putnbr(lstpiece->ret_y);
	write(1, " ", 1);
	ft_putnbr(lstpiece->ret_x);
	write(1, "\n", 1);
	return (1);
}
