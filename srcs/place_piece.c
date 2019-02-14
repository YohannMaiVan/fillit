/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 17:44:38 by yomai-va          #+#    #+#             */
/*   Updated: 2019/02/14 16:12:26 by yomai-va         ###   ########.fr       */
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
	while (first <= xmap)
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

// int		check_place(char **tab, char *map, int piece, int xmap)
// {
// 	int i;

// 	i = 0;
// 	while (tab[piece][i] != '\n')
// 		i++;
// 	while (map[xmap] != '\n')
// 	{
// 		xmap++;
// 	}
// 	while (map[xmap])
// 	{
// 		if (xmap < i)
// 		{
// 			while (!(map[xmap] == '.'))
// 				xmap++;
// 			return (xmap);
// 		}
// 	}
// }


// int		place_piece(char **tab, char *map, int piece, int xmap)
// {
// 	int i;
// 	int	first;

// 	first = 0;
// 	i = 0;
// 	if (!tab[piece])
// 		return (-1);
// 	while (map[xmap])
// 	{
// 		while (tab[piece] && tab[piece][i] != '\0')
// 		{
// 			if (tab[piece][i] != '.')
// 			{
// 				printf("TEST1\n");
// 				if (i == 0)
// 					first = xmap;
// 				if (tab[piece][i + 1] == '\0' && tab[piece][i] == '\n')
// 				{
// 					// printf("retour de nextpoint <%d>\n", nextpoint(map, xmap));
// 					place_piece(tab, map, ++piece, nextpoint(map, xmap));
// 					return (0);
// 				}
// 				else
// 				{
// 					map[xmap++] = tab[piece][i++];
// 				}
// 			}
// 			if (tab[piece][i] == '\n' && tab[piece][i + 1] != '\0')
// 			{
// 				printf("TEST2\n");
// 				i++;
// 				xmap = nextline(map, xmap, first);
// 			}
// 			if (map[xmap] == '\n' && map[xmap + 1] != '\0')
// 			{
// 				printf("TEST3\n");
// 				xmap = nextline(map, xmap, first);
// 				printf("retour de nextpoint <%d>\n", nextpoint(map, xmap));
// 				// xmap = nextpoint(map, xmap);
// 			}
// 		}
// 		printf("TEST5\n");
// 		xmap++;
// 	}
// 	return (0);
// }

// int		place_piece(char **tab, char *map, int piece, int xmap)
// {
// 	int i;
// 	int	first;

// 	first = 0;
// 	i = 0;
// 	if (!tab[piece])
// 		return (-1);
// 	while (tab[piece] && tab[piece][i] != '\0')
// 	{
// 		if (tab[piece][i] != '.')
// 		{
// 			// printf("TEST1\n");
// 			if (i == 0)
// 				first = xmap;
// 			if (tab[piece][i + 1] == '\0' && tab[piece][i] == '\n')
// 			{
// 				printf("\nL'etat de la map: \n%s", map);

// 				// printf("retour de nextpoint <%d>\n", nextpoint(map, xmap));
// 				place_piece(tab, map, ++piece, nextpoint(map, xmap));
// 				return (0);
// 			}
// 			else
// 			{
// 				map[xmap++] = tab[piece][i++];
// 			}
// 		}
// 		if (tab[piece][i] == '\n' && tab[piece][i + 1] != '\0')
// 		{
// 			// printf("TEST2\n");
// 			i++;
// 			xmap = nextline(map, xmap, first);
// 		}
// 		if (map[xmap] == '\n' && map[xmap + 1] != '\0' && map[xmap] != tab[piece][i])
// 		{
// 			// printf("TEST3\n");
// 			xmap = nextline(map, xmap, first);
// 			printf("retour de nextpoint <%d>\n", nextpoint(map, xmap));
// 			fflush(stdout);
// 		}
// 	}
// 	return (0);
// }

int		place_piece(char **tab, char *map, int piece, int xmap)
{
	int i;
	int	first;
	int point;

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
			if (map[xmap] == '.')
			{
				
				map[xmap] = tab[piece][i];
				printf("--------------------> Map: \n%s", map);
			}
			else
				return (-1);
		}
		xmap++;
		i++;
		// printf("MON XMAP <%d>\n", xmap);
		// printf("VALEUR DE i <%d>\n", i);
				fflush(stdout);
		if (tab[piece][i] == '\n')
		{
			i++;
			if (tab[piece][i] == '\0')
			{
				++piece;
				if (!(tab[piece]))
					return (0);
				while (place_piece(tab, map, piece, point) == -1)
				{
				printf("\nL'etat de la map: \n%s", map);
				point++;
				printf("PIECE <%d>\n", piece);
				}
				return (0);
			}
			else if (tab[piece][i] != '\0')
				xmap = nextline(map, xmap, first);
		}
		if (map[xmap] == '\n' && map[xmap + 1] != '\0')
		{
			// printf("TEST3\n");
			xmap = nextline(map, xmap, first);
			printf("retour de nextpoint <%d>\n", nextpoint(map, xmap));
			fflush(stdout);
		}
	}
	return (0);
}