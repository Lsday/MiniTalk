/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 22:23:23 by oronda            #+#    #+#             */
/*   Updated: 2021/10/18 17:41:29 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(const void *content)
{
	t_list	*new;
	void	*c;

	new = malloc(sizeof(new));
	if (!new)
		return (NULL);
	if (!content)
		content = NULL;
	c = (void *)content;
	new->content = c;
	new->next = NULL;
	return (new);
}
