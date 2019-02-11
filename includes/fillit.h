/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 19:56:49 by yomai-va          #+#    #+#             */
/*   Updated: 2019/02/06 21:07:37 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_TETRI_STR_SIZE (21 * 26)

# include "libft.h"

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct	s_tetri
{
	char		piece[4][5];
	char		sep;
}				t_tetri;

char		**stock_tab(char *str);
char		**del_empty_line(char **tab);
void		transform_into_letter(char **tab);
void		ft_print_words_tables(char **tab);
int			nb_pieces(char **tab);
// char		**create_map(char **tab, int size);
char		*create_map(char **tab);
int			place_piece(char **tab, char *map, int piece, int xmap);

#endif
