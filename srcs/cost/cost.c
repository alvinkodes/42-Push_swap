/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:30:51 by akok              #+#    #+#             */
/*   Updated: 2025/06/27 15:54:15 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_to_top(t_data *data, t_stack *target);
static int	get_tot_cost(int cost_a, int cost_b);

t_cost	cal_cost(t_stack *node, t_data *data)
{
	int		stack_size;
	t_cost	cost_info;

	stack_size = data->stack_b.size;
	cost_info.node = node;
	cost_info.cost_a = cost_to_top(data, node);
	cost_info.cost_b = cost_to_place(data, stack_size, node->val, A_TO_B);
	cost_info.tot_cost = get_tot_cost(cost_info.cost_a, cost_info.cost_b);
	return (cost_info);
}

static int	cost_to_top(t_data *data, t_stack *target)
{
	int		pos;
	int		stack_size;
	t_stack	*cur_node;

	stack_size = data->stack_a.size;
	pos = 0;
	cur_node = data->stack_a.head;
	while (cur_node && cur_node != target)
	{
		pos++;
		cur_node = cur_node->next;
	}
	if (pos <= stack_size / 2)
		return (pos);
	return (pos - stack_size);
}

int	cost_to_place(t_data *data, int stack_size, int val, int move_dir)
{
	int	pos;
	int	min_val;
	int	max_val;
	int	target_val;

	min_val = INT32_MAX;
	max_val = INT32_MIN;
	set_min_max(data, &min_val, &max_val, move_dir);
	if (move_dir == A_TO_B)
		target_val = max_val;
	else
		target_val = min_val;
	pos = get_node_pos(data, target_val, move_dir);
	if (val < min_val || val > max_val)
	{
		if (pos <= stack_size / 2)
			return (pos);
		return (pos - stack_size);
	}
	if (move_dir == A_TO_B)
		return (get_insert_pos(&data->stack_b, val, is_between_desc));
	else
		return (get_insert_pos(&data->stack_a, val, is_between_ascd));
}

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
