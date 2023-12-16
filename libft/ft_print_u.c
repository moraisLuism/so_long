/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:16:49 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 09:16:53 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(unsigned int nb)
{
	int	len;
	int	temp;

	len = 0;
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
