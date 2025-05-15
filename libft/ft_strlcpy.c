/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 08:48:32 by ypellegr          #+#    #+#             */
/*   Updated: 2025/04/01 14:16:34 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char src[] = "Hello, World!";
	char dest[20];
	size_t copied;

	copied = ft_strlcpy(dest, src, sizeof(dest));
	printf("Source: %s\n", src);
	printf("Destination: %s\n", dest);
	printf("Length of source: %zu\n", copied);

	return 0;
}
*/