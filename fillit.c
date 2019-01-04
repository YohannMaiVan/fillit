/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:55:31 by yomai-va          #+#    #+#             */
/*   Updated: 2019/01/04 18:14:26 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		ft_check_line(char *str)
{
	int i;
	int n;
	int c;

	i = 0;
	n = 0;
	c = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			c++;
			n--;
		}
		i++;
	}
	if ((str[i - 1] == '\n' && str[i - 2] == '\n') || c > 26)
		return (0);
	if (n == c * 4)
		return (1);
	return (0);
}

int		ft_check_nb_carac(char *str)
{
	int i;
	int cp;

	i = 0;
	cp = 4;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] != '\n')
			i++;
		if (i == cp && str[i++] == '\n')
			cp += 5;
		else
			return (0);
		if (str[i] == '\n')
		{
			i++;
			cp++;
		}
		if (str[i] == '\0')
			return (1);
	}
	return (0);
}

int		ft_check_tetriminos(char *str)
{
	int i;
	int c;
	int n;

	i = 0;
	c = 0;
	n = 1;
	while (str[i] && (str[i] == '.' || str[i] == '\n' || str[i] == '#'))
	{
		if (str[i] && (str[i] == '.' || str[i] == '\n'))
			i++;
		if (str[i++] == '#')
			c++;
		if (str[i] == '\n' && str[i - 1] == '\n')
		{
			if (c != n * 4)
				return (0);
			n++;
		}
	}
	if (c == n * 4)
		return (1);
	return (0);
}

int		ft_check_piece(char *str)
{
	int i;
	int n;
	int j;

	i = 0;
	n = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		if (str[i] == '#')
		{
			if (str[i + 1] == '#')
				n += 2;
			if (str[i + 5] == '#')
			// if ((j != 3) && str[i + 5] == '#')
			// CONDITION A VERIFIER POUR LIGNE FIN DE FICHIER CF TEST12 ET 16 FAUX
				n += 2;
		}
		if ((str[i] == '\n' && str[i + 1] == '\n')
		|| (str[i] == '\n' && str[i + 1] == '\0'))
		{
			if (n != 6 && n != 8)
			{
			printf("PASSAGE DE PRINT et valeur de n <%d>\n", n);
				return (0);
			}
			n = 0;
			j = 0;
		}
		i++;
	}
	return (1);
}

int		main(void)
{
	char *str;
	int fd;

	str = (char*)malloc(sizeof(char) * 547);
	fd = open("test.txt", O_RDONLY);
	bzero(str, 547);
	read(fd, str, 546);
	// printf("Resultat du Check_line RETURN :<%d>", ft_check_line(str));
	// printf("Resultat du Check_nb_carac RETURN :<%d>", ft_check_nb_carac(str));
	// printf("Resultat du Check_tetriminos RETURN :<%d>", ft_check_tetriminos(str));
	printf("Resultat du Check_piece RETURN :<%d>", ft_check_piece(str));
	return (0);
}
