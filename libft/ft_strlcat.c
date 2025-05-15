/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypellegr <ypellegr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 04:15:40 by ypellegr          #+#    #+#             */
/*   Updated: 2025/04/01 16:18:52 by ypellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = 0;
	while (dest[dest_len] && dest_len < nb)
		dest_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dest_len == nb)
		return (nb + src_len);
	i = dest_len;
	j = 0;
	while (src[j] && i + 1 < nb)
		dest[i++] = src[j++];
	if (i < nb)
		dest[i] = '\0';
	return (dest_len + src_len);
}
