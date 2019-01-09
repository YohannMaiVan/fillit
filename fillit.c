/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:55:31 by yomai-va          #+#    #+#             */
/*   Updated: 2019/01/08 18:17:57 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		check_line(char *str)
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

int		check_nb_carac(char *str)
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

int		check_content_grid(char *str)
{
	int i;
	int c;
	int n;

	i = 0;
	c = 0;
	n = 1;
	while (str[i] && (str[i] == '.' || str[i] == '\n' || str[i] == '#'))
	{
		if (str[i] == '#')
			c++;
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			if (c != n * 4)
				return (0);
			n++;
		}
		i++;
	}
	if (c == n * 4)
		return (1);
	return (0);
}

int		count_touch(int *n, int *j)
{
	if (*n != 6 && *n != 8)
		return (0);
	*n = 0;
	*j = 0;
	return (1);
}

// int		check_piece(char *str)
// {
// 	int i;
// 	int n;
// 	int j;

// 	i = 0;
// 	n = 0;
// 	j = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == '\n')
// 			j++;
// 		if (str[i] == '#')
// 		{
// 			if (str[i + 1] == '#')
// 				n += 2;
// 			if ((j != 3) && str[i + 5] == '#')
// 				n += 2;
// 		}
// 		if ((str[i] == '\n') && (str[i + 1] == '\n' || str[i + 1] == '\0'))
// 		{
// 			if (count_touch(&n, &j) == 0)
// 				return (0);
// 			i++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int		count_link(char *str, int n, int j, int i)
{
	if (str[i] == '#')
	{
		if (str[i + 1] == '#')
			n += 2;
		if ((j != 3) && str[i + 5] == '#')
			n += 2;
	}
	return (n);
}

int		check_piece(char *str)
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
		n = count_link(str, n, j, i);
		if ((str[i] == '\n') && (str[i + 1] == '\n' || str[i + 1] == '\0'))
		{
			if (n != 6 && n != 8)
				return (0);
			n = 0;
			j = 0;
			i++;
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
	// fd = open("TEST/error_21", O_RDONLY);
	bzero(str, 547);
	read(fd, str, 546);
	// printf("Resultat du Check_line RETURN :<%d>\n", check_line(str));
	printf("Resultat du Check_nb_carac RETURN :<%d>\n", check_nb_carac(str));
	printf("Resultat du Check_CONTENT_GRID RETURN :<%d>\n", check_content_grid(str));
	printf("Resultat du Check_piece RETURN :<%d>\n", check_piece(str));
	// getchar(); Pour verifier les leaks
	return (0);
}
