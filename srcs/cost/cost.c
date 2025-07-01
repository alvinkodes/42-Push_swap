/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:30:51 by akok              #+#    #+#             */
/*   Updated: 2025/07/01 16:33:17 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_to_top(t_data *data, t_stack *target);
static int	get_tot_cost(int cost_a, int cost_b);

//	cost_a: cost to place a_node in the right position for b_node to insert
//	cost_b: cost to bring target node in stack b to top
//	tot_cost: cost to perform a full insert
t_cost	cal_cost(t_stack *node, t_data *data)
{
	int		stack_size;
	t_cost	cost_info;

	stack_size = data->stack_a.size;
	cost_info.node = node;
	cost_info.cost_a = cost_to_place(data, stack_size, node->val);
	cost_info.cost_b = cost_to_top(data, node);
	cost_info.tot_cost = get_tot_cost(cost_info.cost_a, cost_info.cost_b);
	return (cost_info);
}

//	cost to bring target node in stack_b to top.
//	If closer to top, use rotate. If closer to bottom use reverse rotate.
static int	cost_to_top(t_data *data, t_stack *target)
{
	int		pos;
	int		stack_size;
	t_stack	*cur_node;

	stack_size = data->stack_b.size;
	pos = 0;
	cur_node = data->stack_b.head;
	while (cur_node && cur_node != target)
	{
		pos++;
		cur_node = cur_node->next;
	}
	if (pos <= stack_size / 2)
		return (pos);
	return (pos - stack_size);
}

//	cost to place target node in stack a in the correct pos for b to insert
//	if val to insert < min val or > max val in stack_b, bring cur_min to top
//	otherwise bring the closest biggest value in stack a to top
int	cost_to_place(t_data *data, int stack_size, int val)
{
	int	pos;
	int	max_val;
	int	min_val;

	min_val = INT32_MAX;
	max_val = INT32_MIN;
	set_min_max(data, &min_val, &max_val);
	pos = get_node_pos(data, min_val);
	if (val < min_val || val > max_val)
	{
		if (pos <= stack_size / 2)
			return (pos);
		return (pos - stack_size);
	}
	return (get_insert_pos(&data->stack_a, val));
}

//	positive cost: rotate, negative cost: reverse rotate
//	if both stacks are going to move in the same direction
//	the total cost will be the max among cost_a and cost_b
static int	get_tot_cost(int cost_a, int cost_b)
{
	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
		return (max_ab(cost_a, cost_b));
	if (cost_a < 0)
		cost_a = -cost_a;
	if (cost_b < 0)
		cost_b = -cost_b;
	return (cost_a + cost_b);
}
