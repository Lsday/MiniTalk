/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 22:51:14 by oronda            #+#    #+#             */
/*   Updated: 2021/10/21 09:48:15 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*only_space(char *ptr)
{
	ptr = malloc(sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

static int	ft_is_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, char const *set)
{
	int		l;
	int		i;
	char	*ptr;
	int		j;

	ptr = NULL;
	l = ft_strlen(s);
	i = 0;
	while (ft_is_set(s[i], set))
		i++;
	while (ft_is_set(s[l - 1], set))
		l--;
	if (l < i)
		return (only_space(ptr));
	else
	{
		ptr = malloc(sizeof(char) * (l - i) + 1);
		if (!ptr)
			return (NULL);
		j = 0;
		while (i != l)
			ptr[j++] = s[i++];
		ptr[j] = '\0';
		return (ptr);
	}
}
