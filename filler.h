/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:07:30 by skarev            #+#    #+#             */
/*   Updated: 2018/10/15 17:07:30 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/libft.h"
# include <stdio.h>

#define NRM  "\x1B[0m"
#define BLC  "\x1B[30m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"
#define NONE "\033[0m"

typedef struct      s_lstmap
{
	int				width;
	int				hight;
	char			**map;
	int				player;
	char			mysymbol;
	char			enemysymbol;
	int				x_mypos;
	int				y_mypos;
	int				x_enemypos;
	int				y_enemypos;
}					t_lstmap;

typedef struct      s_lstpiece
{
	int				width;
	int				hight;
	char			**piece;
	int				ret_x;
	int				ret_y;
	int				manhattan;
	int				tmp;
}					t_lstpiece;

void    parce_player(t_lstmap *lstmap);
void	parce_mapsize(t_lstmap *lstmap);
void	parce_map(t_lstmap *lstmap);
void	free_lstmap(t_lstmap *lstmap);
void	start_point_1(t_lstmap *lstmap, int i, int j);
void	start_point_2(t_lstmap *lstmap, int i, int j);
void	parce_piecesize(t_lstpiece *lstpiece);
void	parce_piece(t_lstpiece *lstpiece);

void	algorithm(t_lstmap *lstmap, t_lstpiece *lstpiece);
void	touchdetect(t_lstmap *lstmap, t_lstpiece *lstpiece, int i, int j);
void	disttoenemy(t_lstpiece *lstpiece, t_lstmap *lstmap, int i, int j);
void	dest_starts(t_lstpiece *lstpiece, t_lstmap *lstmap);
int		ft_abs(int n);

void	reparce_map(t_lstmap *lstmap);
void	reparce_piece(t_lstpiece *lstpiece);
void	free_lstpiece(t_lstpiece *lstpiece);
int		print_coords(t_lstpiece *lstpiece);

#endif