/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:36:44 by magrinbe          #+#    #+#             */
/*   Updated: 2018/11/22 19:20:56 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_strlenl(const char *str, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if ((str[i - 1] == c || i == 0) && str[i] != c)
			j++;
		i++;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		o;

	i = 0;
	o = 0;
	tab = (char **)malloc(sizeof(char *) * (ft_strlenl(s, c) + 1));
	if (!s || !tab)
		return (NULL);
	while (s[i] == c)
		i++;
	while (o < ft_strlenl(s, c))
	{
		j = 0;
		tab[o] = (char*)malloc(sizeof(char) * ft_strlen((char*)s));
		while (s[i] && s[i] != c)
			tab[o][j++] = s[i++];
		while (s[i] && s[i] == c)
			i++;
		tab[o][j] = '\0';
		o++;
	}
	tab[o] = 0;
	return (tab);
}
