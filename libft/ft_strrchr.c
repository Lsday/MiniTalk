/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:06:15 by oronda            #+#    #+#             */
/*   Updated: 2021/10/18 16:44:32 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*ptr;
	char	*r;

	r = (char *)s;
	ptr = NULL;
	i = 0;
	len = ft_strlen(r);
	while (i < len)
	{
		if (r[i] == (unsigned char)c)
			ptr = &r[i];
		i++;
	}
	if (r[i] == (unsigned char)c)
		return (ptr = &r[i]);
	if (!ptr)
		return (NULL);
	return (ptr);
}
