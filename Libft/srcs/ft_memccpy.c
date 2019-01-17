/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:26:26 by yomai-va          #+#    #+#             */
/*   Updated: 2018/11/23 21:13:58 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d1;
	unsigned char	*s1;

	d1 = (unsigned char *)dst;
	s1 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d1[i] = s1[i];
		if (s1[i] == (unsigned char)c)
		{
			return (d1 + i + 1);
		}
		i++;
	}
	return (NULL);
}
