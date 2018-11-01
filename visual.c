/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarev <skarev@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:34:09 by skarev            #+#    #+#             */
/*   Updated: 2018/10/26 16:34:11 by skarev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <ncurses.h>

void	print_score_and_winner(char *str)
{
	int				p1;
	int				p2;

	p1 = ft_atoi(&str[10]);
	get_next_line(0, &str);
	p2 = ft_atoi(&str[10]);
	printf("%s%s%s\n", RED, "***********SCORE**********", NONE);
	printf("%s*                        *%s\n", RED, NONE);
	printf(" %s PLAYER 1%s  %sVS%s  %sPLAYER 2 %s \n", \
							GRN, NONE, RED, NONE, MAG, NONE);
	printf("%s*                        *%s\n", RED, NONE);
	printf("    %s%d           %d%s      \n", CYN, p1, p2, NONE);
	printf("%s*                        *%s\n", RED, NONE);
	printf("%s**************************%s\n\n", RED, NONE);
	printf("%s$$$$$$$$$ WINNER $$$$$$$$$%s\n", GRN, NONE);
	printf("%s$                        $%s\n", GRN, NONE);
	if (p1 > p2)
		printf("%s$        PLAYER 1        $%s\n", GRN, NONE);
	else
		printf("%s$%s        %sPLAYER 2%s        %s$%s\n", \
									GRN, NONE, MAG, NONE, GRN, NONE);
	printf("%s$                        $%s\n", GRN, NONE);
	printf(GRN"$$$$$$$$$$$$$$$$$$$$$$$$$$\n"NONE);
}

void	print_map(char *str, int i)
{
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			printf("%s%c%s", CYN, str[i], NONE);
		else if (str[i] == '.')
			printf("%s%c%s", BLC, str[i], NONE);
		else if (str[i] == 'O')
			printf("%s%c%s", GRN, str[i], NONE);
		else if (str[i] == 'X')
			printf("%s%c%s", MAG, str[i], NONE);
		else
			printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

void	print_piece(char *str, int i)
{
	unsigned int	wait;

	while (str[i])
	{
		if (str[i] == '.')
			printf("%s%c%s", YEL, str[i], NONE);
		else if (str[i] == '*')
			printf("%s%c%s", RED, str[i], NONE);
		i++;
	}
	printf("\n");
	wait = 0;
	while (++wait < 999999)
		;
	system("clear");
}

int		main(void)
{
	int				i;
	char			*str;

	while (get_next_line(0, &str) == 1)
	{
		i = 0;
		if (str[i] == 'P')
			printf("%s%s%s\n", CYN, str, NONE);
		else if (str[i] == ' ')
			printf("%s%s%s\n", CYN, str, NONE);
		else if (ft_isdigit(str[i]))
			print_map(str, i);
		else if (str[i] == '=')
			print_score_and_winner(str);
		else
			print_piece(str, i);
	}
}
