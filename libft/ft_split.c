/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:36:31 by oronda            #+#    #+#             */
/*   Updated: 2021/10/21 09:48:12 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	else
		return (0);
}

static char	*ft_get_substr(char const *s, char sep)
{
	int		i;
	int		len;
	char	*result;

	len = 0;
	i = 0;
	while (!ft_is_sep(s[i], sep) && s[i])
	{
		len ++;
		i++;
	}
	result = malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (!ft_is_sep(s[i], sep) && s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

void	ft_cut_str(char const *s, char sep, char **result)
{
	int		i;
	int		j;
	int		k;
	char	*substr;

	i = 0;
	j = 0;
	k = -1;
	while (s[i])
	{
		j = 0;
		while (!ft_is_sep(s[i], sep) && s[i])
		{
			if (!j)
				substr = ft_get_substr(&(s[i]), sep);
			i++;
			j++;
		}
		if (j)
			result[++k] = substr;
		while (ft_is_sep(s[i], sep) && s[i])
			i++;
	}
	result[++k] = 0;
}

static int	ft_count_words(char const *s, char sep)
{
	int	i;
	int	j;
	int	wcount;

	wcount = 0;
	i = 0;
	while (s[i])
	{	
		j = 0;
		while (!ft_is_sep(s[i], sep) && s[i])
		{	
			if (!j)
				wcount++;
			j++;
			i++;
		}
		while (ft_is_sep(s[i], sep) && s[i])
			i++;
	}
	return (wcount);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!result)
		return (NULL);
	ft_cut_str(s, c, result);
	return (result);
}
