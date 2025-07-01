/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:44:24 by akok              #+#    #+#             */
/*   Updated: 2025/07/01 16:33:58 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		pre_sort_push(t_data *data);
static t_cost	get_cheapest(t_data *data);
static void		flush_b_to_a(t_data *data);
static void		bring_min_to_top(t_data *data);

//	pre-sort value in stack a by pushing to stack b until three numbers left
//	sort the three remaining numbers
//	insert value from b back to a
//	bring min val in stack a to top
void	turk_sort(t_data *data)
{
	if (data->stack_a.size <= 3)
		return (sort_under_three(data));
	pre_sort_push(data);
	sort_three(data);
	flush_b_to_a(data);
	bring_min_to_top(data);
}

//	split stack a into 3 chunks (chunk MIN, chunk MID and chunk MAX)
//	send value in chunk MAX to bottom of stack a (ra)
//	send value in chunk MID to top of stack b (pb)
//	send value in chunk MIN to bottom of stack b (pb + rb)
static void	pre_sort_push(t_data *data)
{
	int		pushed;
	int		stack_size;
	t_stack	*cur_node;

	pushed = 0;
	stack_size = data->stack_a.size;
	while (data->stack_a.size > 3 && pushed < stack_size / 2)
	{
		cur_node = data->stack_a.head;
		if (cur_node->index <= stack_size / 2)
		{
			pb(data, 1);
			if (stack_size >= 250 && cur_node->index <= stack_size / 3)
				rb(data, 1);
			pushed++;
		}
		else
			ra(data, 1);
	}
	while (data->stack_a.size > 3)
		pb(data, 1);
}

//	calculate the cheapest cost
static t_cost	get_cheapest(t_data *data)
{
	int		cheapest_cost;
	t_stack	*cur_node;
	t_cost	cheapest_cost_info;
	t_cost	cur_cost_info;

	cheapest_cost = INT32_MAX;
	cur_node = data->stack_b.head;
	while (cur_node)
	{
		cur_cost_info = cal_cost(cur_node, data);
		if (cur_cost_info.tot_cost < cheapest_cost)
		{
			cheapest_cost = cur_cost_info.tot_cost;
			cheapest_cost_info = cur_cost_info;
		}
		if (cheapest_cost_info.tot_cost == 0)
			break ;
		cur_node = cur_node->next;
	}
	return (cheapest_cost_info);
}

//	send the cheapest number in b back to a
static void	flush_b_to_a(t_data *data)
{
	t_cost	cost_info;

	while (data->stack_b.size)
	{
		cost_info = get_cheapest(data);
		do_op(data, &cost_info);
	}
}

// rotate or reverse rotate stack a until min val is at top
static void	bring_min_to_top(t_data *data)
{
	t_cost	cost_info;
	int		min_pos;
	int		max_val;
	int		min_val;

	init_tcost(&cost_info);
	max_val = INT32_MIN;
	min_val = INT32_MAX;
	set_min_max(data, &min_val, &max_val);
	min_pos = get_node_pos(data, min_val);
	if (min_pos <= data->stack_a.size / 2)
		cost_info.cost_a = min_pos;
	else
		cost_info.cost_a = (min_pos - data->stack_a.size);
	rotate_a(data, &cost_info);
}
