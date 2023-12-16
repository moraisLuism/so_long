/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:32:38 by lmorais-          #+#    #+#             */
/*   Updated: 2023/12/01 09:32:46 by lmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_gnl(char **p)
{
	free(*p);
	*p = NULL;
}

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr_gnl(char *s, int c, int flag)
{
	int	i;

	if (flag == 1 && s == NULL)
		return (-5);
	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strnjoin_gnl(char *s1, char *s2, int n)
{
	char	*output;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (s2[i2] == '\0')
		return (NULL);
	output = malloc(ft_strlen_gnl(s1) + n + 1);
	if (output == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			output[i] = s1[i];
			i++;
		}
	}
	while (s2 && s2[i2] != '\0' && i2 < n)
		output[i++] = s2[i2++];
	output[i] = '\0';
	if (s1)
		ft_free_gnl(&s1);
	return (output);
}

char	*ft_strndup_gnl(char *input, int n)
{
	char	*output;
	int		len;
	int		i;

	i = 0;
	len = n;
	output = malloc(len + 1);
	if (output == NULL)
		return (NULL);
	while (input && input[i] != '\0' && i < n)
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
