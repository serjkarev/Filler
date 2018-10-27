/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:25:00 by skarev            #+#    #+#             */
/*   Updated: 2018/10/16 12:25:01 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    parce_player(t_lstmap *lstmap)
{
	int     ret;
	char	*str;

	ret = get_next_line(0, &str);
	if (str[10] == '1')
	{
		lstmap->player = 1;
		lstmap->mysymbol = 'O';
		lstmap->enemysymbol = 'X';
	}
	else
	{
		lstmap->player = 2;
		lstmap->mysymbol = 'X';
		lstmap->enemysymbol = 'O';
	}
	free(str);
}

void	parce_mapsize(t_lstmap *lstmap)
{
	int		i;
	int     ret;
	char	*str;

	i = 8;
	ret = get_next_line(0, &str);
	lstmap->hight = ft_atoi(&str[i]);
	while(ft_isdigit(str[i]))
		i++;
	i += 1;
	lstmap->width = ft_atoi(&str[i]);
	free(str);
	ret = get_next_line(0, &str);
	free(str);
}

void	parce_map(t_lstmap *lstmap)
{
	int		i;
	char	*str;

	i = 0;
	lstmap->map = (char**)malloc(sizeof(char*) * (lstmap->hight + 1));
	while (lstmap->hight > i)
	{
		get_next_line(0, &str);
		lstmap->map[i] = ft_strsub(str, 4, lstmap->width);
		i++;
		free(str);
	}
}

void	parce_start_point(t_lstmap *lstmap)
{
	int		i;
	int		j;

	i = 0;
	while (lstmap->map[i])
	{
		j = 0;
		while (lstmap->map[i][j])
		{
			if (lstmap->map[i][j] == 'X' || lstmap->map[i][j] == 'O')
			{
				if (lstmap->player == 1)
					start_point_1(lstmap, i, j);
				else if (lstmap->player == 2)
					start_point_2(lstmap, i, j);

			}
			j++;
		}
		i++;
	}
}

int     main(void)
{
	t_lstmap    *lstmap;
	t_lstpiece	*lstpiece;

	lstmap = (t_lstmap*)malloc(sizeof(t_lstmap));
	lstpiece = (t_lstpiece*)malloc(sizeof(t_lstpiece));
	parce_player(lstmap);
	parce_mapsize(lstmap);
	parce_map(lstmap);
	parce_piecesize(lstpiece);
	parce_piece(lstpiece);
	parce_start_point(lstmap);
	while (1)
	{
		algorithm(lstmap, lstpiece);
		if (!print_coords(lstpiece))
			break ;
		reparce_map(lstmap);
		reparce_piece(lstpiece);
		system("leaks -q skarev.filler");
		// free_lstpiece(lstpiece);
	}
	// free_lstmap(lstmap);
	return (0);
}