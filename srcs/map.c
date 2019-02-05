/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:55:31 by yomai-va          #+#    #+#             */
/*   Updated: 2019/02/04 15:57:47 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nb_pieces(char **tab)
{
	int o;

	o = 0;

	while (tab[o])
		o++;
	printf("NB DE PIECES <%d>\n", o);
	return (o);
}

// char	*create_map(char **tab)
// {
// 	int		i;
// 	int		o;
// 	int		j;
// 	int		a;
// 	char	*map;

// 	a = 1;
// 	i = 0;
// 	j = 0;
// 	o = ft_sqrt(nb_pieces(tab) * 4);
// 	map = (char *)malloc(sizeof(char) * (o * o + o + 1));
// 	while (i < o * o + o)
// 	{
// 		map[i] = '.';
// 		if (i == (o) * a + j)
// 		{
// 			map[i] = '\n';
// 			a++;
// 			if (a > 1)
// 				j++;
// 		}
// 		i++;
// 	}
// 	map[i] = '\0';
// 	return (map);
// }

char	*create_map(char **tab)
{
	int		i;
	int		o;
	int		j;
	int		a;
	char	*map;

	a = 1;
	i = 0;
	j = 0;
	// o = ft_sqrt(nb_pieces(tab) * 4);
	// COTE DE 6 POUR LES TESTS
	o = 6; 
	map = (char *)malloc(sizeof(char) * (o * o + o + 1));
	while (i < o * o + o)
	{
		map[i] = '.';
		if (i == (o) * a + j)
		{
			map[i] = '\n';
			a++;
			if (a > 1)
				j++;
		}
		i++;
	}
	map[i] = '\0';
	return (map);
}

// char	**create_map(char **tab, int size)
// {
// 	char	**map;
// 	int		line;

// 	line = 0;
// 	map = (char **)malloc(sizeof(char *) * (size + 1));
// 	while (line < size)
// 	{
// 		map[line] = ft_strnew(size);
// 		ft_memset(map[line], '.', size);
// 		line++;
// 	}
// 	map[size] = NULL;
// 	return (map);
// }

// void	free_map(char **map)
// {
// 	int		i;

// 	i = 0;
// 	while (map[i])
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }
