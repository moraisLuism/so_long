/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:17:08 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 09:17:12 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_display_nb(long nb, char *base, int base_size)
{
	long	reste;
	int		printed_len;
	int		temp;

	printed_len = 0;
	if (nb < 0)
		nb = 4294967295 - (nb * -1) + 1;
	reste = nb % base_size;
	nb = nb / base_size;
	if (nb > 0)
	{
		temp = ft_display_nb(nb, base, base_size);
		if (temp == -1)
			return (-1);
		printed_len += temp;
	}
	temp = ft_print_c(base[reste]);
	if (temp == -1)
		return (-1);
	printed_len += temp;
	return (printed_len);
}

int	ft_print_x(long nbr, char *base)
{
	int	base_size;
	int	len;

	base_size = 0;
	while (base[base_size])
		base_size++;
	len = ft_display_nb(nbr, base, base_size);
	if (len == -1)
		return (-1);
	return (len);
}
