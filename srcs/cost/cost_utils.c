/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:34:43 by akok              #+#    #+#             */
/*   Updated: 2025/07/01 16:33:00 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_pos(t_data *data, int val)
{
	int		pos;
	t_stack	*cur_node;

	pos = 0;
	cur_node = data->stack_a.head;
	while (cur_node)
	{
		if (cur_node->val == val)
			break ;
		pos++;
		cur_node = cur_node->next;
	}
	return (pos);
}

int	get_insert_pos(t_info *stack, int val)
{
	int		pos;
	int		cur_val;
	int		next_val;
	t_stack	*cur_node;

	pos = 1;
	cur_node = stack->head;
	while (cur_node)
	{
		cur_val = cur_node->val;
		if (cur_node->next == NULL)
			next_val = stack->head->val;
		else
			next_val = cur_node->next->val;
		if (val > cur_val && val < next_val)
			break ;
		pos++;
		cur_node = cur_node->next;
	}
	if (pos <= stack->size / 2)
		return (pos);
	return (pos - stack->size);
}

void	init_tcost(t_cost *data)
{
	data->node = NULL;
	data->cost_a = 0;
	data->cost_b = 0;
	data->tot_cost = 0;
}

void	set_min_max(t_data *data, int *min_val, int *max_val)
{
	t_stack	*cur_node;

	cur_node = data->stack_a.head;
	while (cur_node)
	{
		if (cur_node->val < *min_val)
			*min_val = cur_node->val;
		if (cur_node->val > *max_val)
			*max_val = cur_node->val;
		cur_node = cur_node->next;
	}
}
