/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:14:06 by yomai-va          #+#    #+#             */
/*   Updated: 2018/11/22 14:54:07 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const	char	*d1;
	size_t			i;

	i = 0;
	d1 = (const char *)s;
	while (i < n)
	{
		if (d1[i] == (char)c)
		{
			return ((void*)(s + i));
		}
		i++;
	}
	return (NULL);
}
