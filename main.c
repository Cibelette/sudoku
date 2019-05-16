/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomoulin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 13:58:14 by lomoulin          #+#    #+#             */
/*   Updated: 2019/02/17 12:19:04 by lomoulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int	main(int ac, char **av)
{
	int			map[N][N];
	t_result	result;

	result.solutions = 0;
	if (ac != 10 || has_input_error(av))
	{
		ft_putstr("Error\n");
	}
	else
	{
		parse_map(av, map);
		if (is_map_invalid(map))
		{
			ft_putstr("Error\n");
			return (0);
		}
		solve(map, 0, 0, &result);
		if (result.solutions > 1)
			ft_putstr("Error\n");
		else
			print_map(result.map);
	}
	return (0);
}
