/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 18:55:31 by yomai-va          #+#    #+#             */
/*   Updated: 2019/01/03 22:21:19 by yomai-va         ###   ########.fr       */
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

int		main(void)
{
	char *str;
	int fd;

	str = (char*)malloc(sizeof(char) * 547);
	fd = open("test.txt", O_RDONLY);
	bzero(str, 547);
	read(fd, str, 546);
	printf("%d", ft_check_nb_carac(str));
	return (0);
}
