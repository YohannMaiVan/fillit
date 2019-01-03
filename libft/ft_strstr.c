/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:59:09 by magrinbe          #+#    #+#             */
/*   Updated: 2018/11/22 19:24:33 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_boolean(const char *s1, const char *s2, int n)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		i++;
		if (i == n)
			return (1);
	}
	return (0);
}

char			*ft_strstr(const char *str, const char *to_find)
{
	int i;

	i = 0;
	while (str[i] != to_find[0] && str[i] != '\0')
		i++;
	if (ft_strcmp(to_find, "") == 0)
		return ((char *)str);
	if (ft_strlen(str) < ft_strlen(to_find))
		return (0);
	while (str[i])
	{
		if (ft_boolean(&str[i], to_find, ft_strlen(to_find)) == 1)
			return ((char *)&str[i]);
		else
			i++;
	}
	return (0);
}
