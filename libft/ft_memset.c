/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:14:00 by ypellegr          #+#    #+#             */
/*   Updated: 2025/04/01 16:24:24 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned char	*s;

	s = ((unsigned char *)pointer);
	while (count--)
		*s++ = (unsigned char)value;
	return (pointer);
}
