/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:42:07 by akok              #+#    #+#             */
/*   Updated: 2025/07/01 13:57:17 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index_from_arr(t_data *data, int **arr)
{
	t_stack	*cur_node;
	int		stack_size;

	cur_node = data->stack_a.head;
	stack_size = data->stack_a.size;
	while (cur_node)
	{
		cur_node->index = binary_search(*arr, cur_node->val, stack_size);
		cur_node = cur_node->next;
	}
}

void	assign_index(t_data *data, int **arr)
{
	int		i;
	t_stack	*cur_node;

	*arr = (int *)malloc(data->stack_a.size * sizeof(int));
	cur_node = data->stack_a.head;
	i = 0;
	while (cur_node)
	{
		(*arr)[i++] = cur_node->val;
		cur_node = cur_node->next;
	}
	quicksort(*arr, 0, data->stack_a.size - 1);
	assign_index_from_arr(data, arr);
}
