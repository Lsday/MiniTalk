/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:56:10 by oronda            #+#    #+#             */
/*   Updated: 2021/08/14 22:16:27 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

#define INT_MAX 2147483647

int	safe_mult(int a, int b)
{
	if (b > INT_MAX / a)
		return (-1);
	else if (a > INT_MAX / b)
		return (-1);
	return (a * b);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size <= 0 || nmemb <= 0)
	{
		ptr = malloc(0);
		return (ptr);
	}
	if (!safe_mult(nmemb, size))
		return (NULL);
	ptr = (void *)malloc(safe_mult(nmemb, size));
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
