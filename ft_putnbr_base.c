/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdessm <mabdessm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:34:52 by mabdessm          #+#    #+#             */
/*   Updated: 2024/05/07 16:33:28 by mabdessm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	int	i;

	i = 0;
	if (nbr >= ft_strlen(base))
	{
		i += ft_putnbr_base(nbr / ft_strlen(base), base);
		i += ft_putnbr_base(nbr % ft_strlen(base), base);
	}
	if (nbr >= 0 && nbr < ft_strlen(base))
	{
		ft_putchar(base[nbr]);
		++i;
	}
	return (i);
}
