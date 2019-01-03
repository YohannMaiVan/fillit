/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:45:25 by magrinbe          #+#    #+#             */
/*   Updated: 2018/11/22 19:38:42 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_balls(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] == s2[i] && i < n)
	{
		i++;
		if (i == n)
			return (1);
	}
	return (0);
}

char			*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;

	i = 0;
	while (str[i] != to_find[0] && str[i] != '\0')
		i++;
	if (n <= 0)
		return (0);
	if (ft_strcmp(to_find, "") == 0)
		return (((char *)str));
	if (ft_strlen(str) < ft_strlen(to_find))
		return (0);
	while (str[i] && i < n)
	{
		if (ft_balls(&str[i], to_find, ft_strlen(to_find)) == 1)
		{
			if (ft_strlen(to_find) > n - i)
				return (0);
			return ((char *)&str[i]);
		}
		else
			i++;
	}
	return (0);
}
