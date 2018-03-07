/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 14:09:10 by tgreil            #+#    #+#             */
/*   Updated: 2018/03/04 12:44:39 by mgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	if ((nb < 0 ? -nb : nb) < 10 && nb != INT_MIN)
	{
		if (nb < 0)
			ft_putchar('-');
		ft_putchar((nb < 0 ? -nb : nb) + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
		ft_putchar((nb < 0 ? -nb : nb) + '0');
	}
}
