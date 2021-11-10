/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 23:00:38 by oronda            #+#    #+#             */
/*   Updated: 2021/10/18 16:41:40 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*r;

	r = (char *)s;
	i = 0;
	while (r[i])
	{
		if (r[i] == (unsigned char)c)
			return (&r[i]);
		i++;
	}
	if (r[i] == (unsigned char)c)
		return (&r[i]);
	return (NULL);
}
