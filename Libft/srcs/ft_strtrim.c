/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:37:02 by yomai-va          #+#    #+#             */
/*   Updated: 2018/12/04 17:15:38 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

static	int		ft_check_space(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_blank(str[i]) == 1)
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	if (!s)
		return (NULL);
	start = ft_check_space((char *)s);
	i = ft_strlen(s) - 1;
	while (i > start && ft_isspace(s[i]) == 1)
		i--;
	end = i;
	if (!(str = (char *)malloc(sizeof(char) * ((end - start) + 1))))
		return (NULL);
	str = ft_strsub(s, start, ((end + 1) - start));
	return (str);
}
