/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_col.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:15:48 by yomai-va          #+#    #+#             */
/*   Updated: 2019/01/29 18:07:14 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**tranform_line(char **tab)
{
	int i;
	int o;

	o = 0;
	while (tab[o])
	{
		i = 0;
		while (tab[o][i])
		{
			if (tab[o][i] == '.' && tab[o][i + 1] == '.'
				&& tab[o][i + 2] == '.' && tab[o][i + 3] == '.')
			{
				while (tab[o][i] == '.')
				{
					tab[o][i] = '?';
					i++;
				}
				i++;
			}
			else
				i = i + 5;
		}
		o++;
	}
	return (tab);
}

char	**tranform_colonne(char **tab)
{
	int i;
	int o;

	o = 0;
	while (tab[o])
	{
		i = 0;
		while (tab[o][i] != '\n')
		{
			if ((tab[o][i] == '.' || tab[o][i] == '?') && (tab[o][i + 5] == '.'
			|| tab[o][i + 5] == '?') && (tab[o][i + 10] == '.' || tab[o][i + 10]
			== '?') && (tab[o][i + 15] == '.' || tab[o][i + 15] == '?'))
			{
				tab[o][i] = '?';
				tab[o][i + 5] = '?';
				tab[o][i + 10] = '?';
				tab[o][i + 15] = '?';
			}
			i++;
		}
		o++;
	}
	return (tab);
}

char	**get_the_fuckin_piece(char **tab)
{
	int		i;
	int		o;
	int		j;
	char	str[11];

	o = 0;
	while (tab[o])
	{
		i = 0;
		j = 0;
		while (tab[o][i])
		{
			if (tab[o][i] != '?')
				str[j++] = tab[o][i];
			i++;
		}
		str[j] = '\0';
		ft_bzero(tab[o], 21);
		j = 0;
		i = 0;
		while (str[j])
			tab[o][i++] = str[j++];
		o++;
	}
	return (tab);
}

int		main(void)
{
	char *str;
	int fd;
	char **tab;

	str = (char*)malloc(sizeof(char) * 547);
	fd = open("test.txt", O_RDONLY);

	bzero(str, 547);
	read(fd, str, 546);
	tab = stock_tab(str);
	int size = ft_sqrt(nb_pieces(tab) * 4);

	char **map = create_map(tab, size);

	for (int line = 0; line < size; line++)
	{
		// printf("%s\n", map[line]);
		for (int col = 0; col < size; col++) {
			printf("%c", map[line][col]);
		}
		printf("\n");
	}
	// tranform_line(tab);
	// tranform_colonne(tab);
	// del_empty_line(tab);
	// get_the_fuckin_piece(tab);
	// ft_print_words_tables(tab);
	return (0);
}

// MAIN POUR TESTER CREATE MAP

// int size = ft_sqrt(nb_pieces(tab) * 4);

// char **map = create_map(tab, size);

// for (int line = 0; line < size; line++)  {
// 	// printf("%s\n", map[line]);
// 	for (int col = 0; col < size; col++) {
// 		printf("%c", map[line][col]);
// 	}
// 	printf("\n");
// }
