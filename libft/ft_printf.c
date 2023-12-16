/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:17:40 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 09:17:44 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		printed_lengh;
	size_t	i;
	va_list	args_list;

	va_start(args_list, str);
	i = -1;
	printed_lengh = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			if (ft_format(str, i++, &printed_lengh, &args_list) == -1)
				return (-1);
		}
		else if (i < ft_strlen(str))
		{
			if (ft_print_c((unsigned char)str[i]) == -1)
				return (-1);
			printed_lengh += 1;
		}
	}
	va_end(args_list);
	return (printed_lengh);
}
