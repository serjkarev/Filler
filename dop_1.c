/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:24:56 by skarev            #+#    #+#             */
/*   Updated: 2018/10/19 14:24:57 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	start_point_1(t_lstmap *lstmap, int i, int j)
{
	if (lstmap->map[i][j] == 'O')
	{
		lstmap->x_mypos = j;
		lstmap->y_mypos = i;
	}
	else if (lstmap->map[i][j] == 'X')
	{
		lstmap->x_enemypos = j;
		lstmap->y_enemypos = i;
	}
}

void	start_point_2(t_lstmap *lstmap, int i, int j)
{
	if (lstmap->map[i][j] == 'X')
	{
		lstmap->x_mypos = j;
		lstmap->y_mypos = i;
	}
	else if (lstmap->map[i][j] == 'O')
	{
		lstmap->x_enemypos = j;
		lstmap->y_enemypos = i;
	}
}

void	parce_piecesize(t_lstpiece *lstpiece)
{
	int		i;
	int		ret;
	char	*str;

	i = 6;
	ret = get_next_line(0, &str);
	lstpiece->hight = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	i += 1;
	lstpiece->width = ft_atoi(&str[i]);
	free(str);
}

void	reparce_map(t_lstmap *lstmap)
{
	int		i;
	char	*str;

	i = 0;
	get_next_line(0, &str);
	ft_strdel(&str);
	get_next_line(0, &str);
	ft_strdel(&str);
	while (lstmap->hight > i)
	{
		get_next_line(0, &str);
		lstmap->map[i] = ft_strcpy(lstmap->map[i], str + 4);
		i++;
		ft_strdel(&str);
	}
}

void	parce_piece(t_lstpiece *lstpiece)
{
	int		i;
	char	*str;

	i = 0;
	lstpiece->piece = (char**)ft_memalloc(sizeof(char*) * \
									(lstpiece->hight + 1));
	while (lstpiece->hight > i)
	{
		get_next_line(0, &str);
		lstpiece->piece[i] = ft_strdup(str);
		i++;
		free(str);
	}
}
