/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:44:38 by yomai-va          #+#    #+#             */
/*   Updated: 2019/02/19 13:51:47 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nextline(char *map, int xmap, int first)
{
	int line;
	int sizemap;

	sizemap = 0;
	line = 0;
	while (map[sizemap])
		sizemap++;
	while (map[line] != '\n')
		line++;
	while (map[xmap] != '\n')
		xmap++;
	if (map[xmap] == '\n' && map[xmap + 1] != '\0')
	{
		while (first < xmap)
			first = first + line + 1;
		if (first < sizemap)
			return (first);
		else
			return (-1);
	}
	else
		return (-1);
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
	int		i;
	int		first;
	int		point;
	char	*save;

	save = NULL;
	point = 0;
	first = 0;
	i = 0;
	if (!tab[piece])
		return (-1);
	if (i == 0)
		first = xmap;
	while (tab[piece] && tab[piece][i] != '\0')
	{
		if (tab[piece][i] != '.' && tab[piece][i] != '\0')
		{
			if (map[xmap] == '.' && tab[piece] && map[xmap])
			{
				map[xmap] = tab[piece][i];
				printf("--------------------> Map: \n%s", map);
			}
			else
				return (-1);
		}
		xmap++;
		i++;
		fflush(stdout);
		if (tab[piece][i] == '\n')
		{
			i++;
			if (tab[piece][i] == '\0')
			{
				++piece;
				if (!(tab[piece]))
					return (0);
				save = ft_strdup(map);
				while (place_piece(tab, map, piece, point) == -1)
				{
					ft_strcpy(map, save);
					fflush(stdout);
					point++;
					fflush(stdout);
					if (map[point] == '\0')
						return (-1);
				}
				return (0);
			}
			else if (tab[piece][i] != '\0')
				// if (!(xmap = nextline(map, xmap, first) == -1))
				// 	return (0);
				{
					if (nextline(map, xmap, first) == -1)
						return (0);
					xmap = nextline(map, xmap, first);
				}
		}
	}
	return (0);
}

			// printf("VALEUR DE XMAP<%d>\n", xmap);
			// printf("VALUE MAP XMAP <%c>\n", map[xmap]);
			// printf("VALUE COUNTER XMAP <%d>\n", xmap);
			// printf("VALUE TAB[PIECE][I] <%c>\n", tab[piece][i]);
			// printf("VALUE MAP XMAP <%c>\n", map[xmap]);
			// printf("VALUE COUNTER XMAP <%d>\n", xmap);
			// printf("MON XMAP <%d>\n", xmap);
			// printf("VALEUR DE i <%d>\n", i);
			// printf("VALUE TAB[PIECE][I] <%c>\n", tab[piece][i]);
			// printf("VALUE DE SAVE \n%s \n", save);
			// printf("\nL'etat de la map: \n%s", map);
			// printf("PASSAGE DANS BOUCLE ERREUR valeur de point <%d>\n", point);
