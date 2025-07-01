/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:34:42 by akok              #+#    #+#             */
/*   Updated: 2025/07/01 13:42:36 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		*index_arr;
	t_data	data;

	if (ac == 1)
		return (0);
	init_stack(&data);
	parse_input(av + 1, &data);
	if (data.stack_a.head == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (1);
	}
	assign_index(&data, &index_arr);
	if (is_sorted(&data))
		return (0);
	turk_sort(&data);
	free(index_arr);
	ps_lstclear(&data.stack_a.head);
	ps_lstclear(&data.stack_b.head);
	return (0);
}
