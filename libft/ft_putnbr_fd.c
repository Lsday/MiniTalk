/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:26:15 by oronda            #+#    #+#             */
/*   Updated: 2021/08/08 22:29:59 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unb;

	if (n < 0)
	{
		unb = (unsigned int)(-1 * n);
		ft_putchar_fd('-', fd);
	}
	else
		unb = (unsigned int)n;
	if (unb >= 10)
	{
		ft_putnbr_fd(unb / 10, fd);
		ft_putchar_fd((unb % 10) + '0', fd);
	}
	else
		ft_putchar_fd(unb + '0', fd);
}
