/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 20:36:38 by magrinbe          #+#    #+#             */
/*   Updated: 2018/11/27 20:04:17 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	x;

	x = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((((unsigned char*)dst)[i] = ((unsigned char*)src)[i]) == x)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
