/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:44:38 by yomai-va          #+#    #+#             */
/*   Updated: 2019/02/05 20:17:24 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nextline(char *map, int xmap, int first)
{
	int line;

	line = 0;
	while (map[line] != '\n')
		line++;
	while (map[xmap] != '\n')
		xmap++;
	while (first < xmap)
		first = first + line + 1;
	if (first > line * line)
		return (-1);
	return (first);
}

char	*place_piece(char **tab, char *map)
{
	int i;
	int xmap;
	int piece;
	int	first;

	xmap = 0;
	first = 0;
	i = 0;
	piece = 0;
	while (map[xmap])
	{
		while (tab[piece][i])
		{
			if (map[xmap])
			{
				if (i == 0)
					first = xmap;
				map[xmap++] = tab[piece][i++];
			}
			if (tab[piece][i] == '\n')
			{
				i++;
				xmap = nextline(map, xmap, first);
				printf("TEST2\n");
			}
			if (map[xmap] == '\n')
			{
				xmap = nextline(map, xmap, first);
				printf("TEST3\n");
			}
		}
		xmap++;
	}
	return (map);
}
