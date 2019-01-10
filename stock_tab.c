/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:05:09 by yomai-va          #+#    #+#             */
/*   Updated: 2019/01/10 20:40:19 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int			count_line(char *str)
{
	int i;
	int n;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

char		**stock_tab(char *str)
{
	int		i;
	int		j;
	int		o;
	char	**tab;

	i = 0;
	o = 0;
	tab = NULL;

	tab = (char **)malloc(sizeof(char *) * ((count_line(str) + 1) / 5) + 1);
	if (!str || !tab)
		return (NULL);
	while (o < ((count_line(str) + 1) / 5))
	{
		j = 0;
		tab[o] = (char*)malloc(sizeof(char) * 20 + 1);
		while (str[i] && (str[i] != '\n' || str[i - 1] != '\n'))
		{
			tab[o][j] = str[i];
			i++;
			j++;
		}
		if (str[i] == '\n' || str[i - 1] == '\n')
			i++;
		tab[o][j] = '\0';
		o++;
	}
	tab[o] = 0;
	return (tab);
}

void	ft_print_words_tables(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_putchar(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	transform_into_letter(char **tab)
{
	int		i;
	int		j;
	char	k;

	i = 0;
	k = 'A';
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				tab[i][j] = k;
			if (tab[i][j] == '.')
				tab[i][j] = '?';
			j++;
		}
		k++;
		i++;
	}
}
// FONCTION A CORRIGER 
void	del_empty_line(char **tab)
{
	int		i;
	int		j;
	char	k;

	i = 0;
	while (tab[i])
	{
		j = 0;
		k = 0;
		// while (tab[i][j] != '\n' && tab[i][j] == '?')
		while (tab[i][j])
		{
			if (tab[i][k] == '?')
				k++;
			if (k == 4 && tab[i][j] == '\n')
			{
				k = 0;
				j++;
				while (tab[i][j])
				{
					tab[i][k] = tab[i][j];
					k++;
					j++;
				}
			}
			j++;
		}
		i++;
	}
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
	int i  = 0;
	transform_into_letter(tab);
	del_empty_line(tab);
	ft_print_words_tables(tab);
	// printf("Resultat du Check_line RETURN :<%d>\n", check_line(str));
	// getchar(); Pour verifier les leaks
	return (0);
}
