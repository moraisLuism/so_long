/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:15:46 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 09:15:50 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intmin(void)
{
	if (ft_print_s("-2147483648") == -1)
		return (-1);
	return (11);
}

static int	ft_neg(int nb, int *len)
{
	int	temp;

	if (ft_print_c('-') == -1)
		return (-1);
	*len += 1;
	nb *= -1;
	temp = ft_print_di(nb);
	if (temp == -1)
		return (-1);
	*len += temp;
	return (*len);
}

int	ft_print_di(int nb)
{
	int	len;
	int	temp;

	len = 0;
	if (nb == -2147483648)
		return (ft_intmin());
	if (nb < 0)
		return (ft_neg(nb, &len));
	if (nb >= 10)
	{
		temp = ft_print_di(nb / 10);
		if (temp == -1)
			return (-1);
		len += temp;
		if (ft_print_c((nb % 10) + '0') == -1)
			return (-1);
		len += 1;
	}
	else
	{
		if (ft_print_c(nb + '0') == -1)
			return (-1);
		len += 1;
	}
	return (len);
}
