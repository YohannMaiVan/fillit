/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:44:38 by yomai-va          #+#    #+#             */
/*   Updated: 2019/02/11 20:22:28 by yomai-va         ###   ########.fr       */
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

int		nextpoint(char *map, int xmap)
{
	xmap = 0;
	while (map[xmap] != '.')
	{
		if (map[xmap] == '\0')
			return (-1);
		xmap++;
	}
	return (xmap);
}

int		place_piece(char **tab, char *map, int piece, int xmap)
{
	int i;
	int	first;

	first = 0;
	i = 0;
	if (!tab[piece])
		return (-1);
	while (map[xmap])
	{
		while (tab[piece] && tab[piece][i])
		{
			if (tab[piece][i] != '\0')
			{
				printf("TEST1\n");
				if (i == 0)
					first = xmap;
				if (tab[piece][i + 1] == '\0' && tab[piece][i] == '\n')
				{
					printf("retour de nextpoint <%d>", nextpoint(map, xmap));
					place_piece(tab, map, ++piece, nextpoint(map, xmap));
					return (0);
				}
				else
					map[xmap++] = tab[piece][i++];
			}
			if (tab[piece][i] == '\n' && tab[piece][i + 1] != '\0')
			{
				printf("TEST2\n");
				i++;
				xmap = nextline(map, xmap, first);
			}
			if (map[xmap] == '\n' && map[xmap + 1] != '\0')
			{
				printf("TEST3\n");
				xmap = nextline(map, xmap, first);
			}
		}
		xmap++;
	}
	return (0);
}
