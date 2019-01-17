/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:35:14 by yomai-va          #+#    #+#             */
/*   Updated: 2018/11/22 16:01:02 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s01;
	unsigned char	*s02;

	i = 0;
	s01 = (unsigned char*)s1;
	s02 = (unsigned char*)s2;
	while (i < n)
	{
		if (s01[i] < s02[i] || s01[i] > s02[i])
			return (s01[i] - s02[i]);
		i++;
	}
	return (0);
}
