/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrinbe <magrinbe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:45:41 by magrinbe          #+#    #+#             */
/*   Updated: 2018/11/21 16:27:12 by magrinbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_l(const char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < size)
	{
		i++;
	}
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	dstlen = ft_strlen_l(dst, size);
	i = 0;
	while (src[i] && (i + dstlen + 1) < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	if (dstlen - size > 0)
		dst[dstlen + i] = '\0';
	return (dstlen + ft_strlen(src));
}
