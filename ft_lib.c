/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:40:00 by lomoulin          #+#    #+#             */
/*   Updated: 2019/02/16 23:40:28 by lomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	while (*str != '\0')
		ft_putchar(*str++);
}

unsigned int	ft_strlen(char *str)
{
	unsigned len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
