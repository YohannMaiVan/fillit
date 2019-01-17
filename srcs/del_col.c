/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_col.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 18:15:48 by yomai-va          #+#    #+#             */
/*   Updated: 2019/01/16 23:01:01 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**del_empty_column(char **tab)
{
	int o;
	int l;

	o = 0;
	while (tab[o])
	{
		l = 0;
		// while (tab[o][l])
		// {
            while (tab[o][l] == '.')
            {
                if (tab[o][l] == '.' && tab[o][l + 5] == '.' &&
			tab[o][l + 10] == '.' && tab[o][l + 15] == '.' &&
            tab[o][l + 1] != '\n')
            {
                tab[o][l] = tab[o][l + 1];
                tab[o][l + 5] = tab[o][l + 6];
                tab[o][l + 10] = tab[o][l + 11];
                tab[o][l + 15] = tab[o][l + 16];
            }
                l++;
            }
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
	// fd = open("TEST/error_21", O_RDONLY);
	bzero(str, 547);
	read(fd, str, 546);
	tab = stock_tab(str);
	// int i  = 0;
	tab = del_empty_line(tab);
	transform_into_letter(tab);
    tab = del_empty_column(tab);
	ft_print_words_tables(tab);
	// printf("Resultat du Check_line RETURN :<%d>\n", check_line(str));
	// getchar(); Pour verifier les leaks
	return (0);
}