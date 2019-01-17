/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomai-va <yomai-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:26:35 by yomai-va          #+#    #+#             */
/*   Updated: 2018/11/21 21:07:23 by yomai-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_max_neg(void)
{
	ft_putstr("-2147483648");
}

void			ft_putnbr(int nb)
{
	if (nb == -2147483648)
		ft_max_neg();
	else
	{
		if (nb < 0)
		{
			nb = nb * -1;
			ft_putchar('-');
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
			ft_putchar(nb + '0');
	}
}
