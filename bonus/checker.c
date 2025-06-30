/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:32:29 by akok              #+#    #+#             */
/*   Updated: 2025/06/30 10:23:53 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_stack(t_data *data)
{
	data->stack_a.head = NULL;
	data->stack_a.tail = NULL;
	data->stack_a.size = 0;
	data->stack_b.head = NULL;
	data->stack_b.tail = NULL;
	data->stack_b.size = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		return (0);
	init_stack(&data);
	parse_input(av + 1, &data);
	if (data.stack_a.head == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (255);
	}
	run_checker(0, &data);
	if (is_sorted(&data) && data.stack_b.head == NULL)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ps_lstclear(&data.stack_a.head);
	ps_lstclear(&data.stack_b.head);
	return (0);
}
