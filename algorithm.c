/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:08:36 by skarev            #+#    #+#             */
/*   Updated: 2018/10/19 18:08:36 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	algorithm(t_lstmap *lstmap, t_lstpiece *lstpiece)
{
	int		i;
	int		j;

	i = 0;
	lstpiece->ret_x = 0;
	lstpiece->ret_y = 0;
	lstpiece->manhattan = 1000;
	while (lstmap->map[i + lstpiece->hight - 1])
	{
		j = 0;
		while (lstmap->map[i + lstpiece->hight - 1][j + lstpiece->width - 1])
		{
			touchdetect(lstmap, lstpiece, i, j);
			j++;
		}
		i++;
	}
	dest_starts(lstpiece, lstmap);
}

void	touchdetect(t_lstmap *lstmap, t_lstpiece *lstpiece, int i, int j)
{
	int		y;
	int		x;
	int		touch;

	y = 0;
	touch = 0;
	while (lstpiece->piece[y])
	{
		x = 0;
		while (lstpiece->piece[y][x])
		{
			if ((lstmap->map[i + y][j + x] == lstmap->mysymbol && lstpiece->piece[y][x] == '*') || \
			(lstmap->map[i + y][j + x] == 'o' && lstpiece->piece[y][x] == '*'))
				touch += 1;
			else if(lstmap->map[i + y][j + x] == lstmap->enemysymbol && lstpiece->piece[y][x] == '*')
				return ;
			x++;
		}
		y++;
	}
	if (touch == 1)
		disttoenemy(lstpiece, lstmap, i, j);
}

void	disttoenemy(t_lstpiece *lstpiece, t_lstmap *lstmap, int i, int j)
{
	int		y;
	int		x;
	int		tmp;

	y = 0;
	tmp = 0;
	lstmap->x_enemypos = 0;
	lstmap->y_enemypos = 0;
	while (lstmap->map[y])
	{
		x = 0;
		while (lstmap->map[y][x])
		{
			if (lstmap->map[y][x] == lstmap->enemysymbol)
			{
				tmp = ft_abs(x - j) + ft_abs(y - i);
				if (tmp < lstpiece->manhattan)
				{
					lstpiece->manhattan = tmp;
					lstpiece->ret_x = j;
					lstpiece->ret_y = i;
					lstmap->x_enemypos = x;
					lstmap->y_enemypos = y;

				}
			}
			x++;
		}
		y++;
	}
}

void	dest_starts(t_lstpiece *lstpiece, t_lstmap *lstmap)
{
	int		i;
	int		j;
	int		manh;
	int		tmp;

	manh = 0;
	tmp = 1000;
	i = lstpiece->ret_y;
	j = lstpiece->ret_x;
	while (lstmap->map[i])
	{
		while (lstmap->map[i][j])
		{
			if (lstmap->map[i][j] == '*')
			{
				manh = ft_abs(lstmap->x_enemypos - j) + ft_abs(lstmap->y_enemypos - i);
				if (manh < tmp)
				{
					tmp = manh;
					lstpiece->ret_x = j;
					lstpiece->ret_y = i;
				}
			}
			j++;
		}
		i++;
	}
}

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	reparce_piece(t_lstpiece *lstpiece)
{
	int		i;
	char	*str;

	i = 0;
	parce_piecesize(lstpiece);
	lstpiece->piece = (char**)ft_memalloc(sizeof(char*) * (lstpiece->hight + 1));
	while (lstpiece->hight > i)
	{
		get_next_line(0, &str);
		lstpiece->piece[i] = (char*)ft_memalloc(sizeof(char) * (lstpiece->width + 1));
		lstpiece->piece[i] = ft_strcpy(lstpiece->piece[i], str);
		i++;
		free(str);
	}
}

int		print_coords(t_lstpiece *lstpiece)
{
	// system("leaks -q skarev.filler");
	if (lstpiece->ret_x == 0 && lstpiece->ret_y == 0)
	{
		write(1, "0", 1);
		return (0);
	}
	ft_putnbr(lstpiece->ret_y);
	write(1, " ", 1);
	ft_putnbr(lstpiece->ret_x);
	write(1, "\n", 1);
	return (1);
}
