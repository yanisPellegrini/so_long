/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:25:03 by ypellegr          #+#    #+#             */
/*   Updated: 2025/04/04 12:21:39 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	get_num_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, int n, int len)
{
	int	sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	str[len] = '\0';
	while (--len >= 0 && str[len] != '-')
	{
		str[len] = (n % 10) * sign + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = get_num_length(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, len + 1);
	fill_str(str, n, len);
	return (str);
}
