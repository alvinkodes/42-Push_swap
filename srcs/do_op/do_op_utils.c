/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:27:07 by akok              #+#    #+#             */
/*   Updated: 2025/07/01 16:39:45 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check if both cost a and cost b is positive
// if yes, use rr to move both
static void	rotate_both_up(t_data *data, t_cost *cost_info)
{
	while (cost_info->cost_a > 0 && cost_info->cost_b > 0)
	{
		rr(data, 1);
		cost_info->cost_a--;
		cost_info->cost_b--;
	}
}

//	check if both cost a and cost b is negative
//	if yes, use rrr to move both
static void	rotate_both_down(t_data *data, t_cost *cost_info)
{
	while (cost_info->cost_a < 0 && cost_info->cost_b < 0)
	{
		rrr(data, 1);
		cost_info->cost_a++;
		cost_info->cost_b++;
	}
}

void	rotate_both(t_data *data, t_cost *cost_info)
{
	if (cost_info->cost_a >= 0 && cost_info->cost_b >= 0)
		rotate_both_up(data, cost_info);
	else if (cost_info->cost_a <= 0 && cost_info->cost_b <= 0)
		rotate_both_down(data, cost_info);
}

void	rotate_a(t_data *data, t_cost *cost_info)
{
	if (cost_info->cost_a > 0)
	{
		while (cost_info->cost_a > 0)
		{
			ra(data, 1);
			cost_info->cost_a--;
		}
	}
	else if (cost_info->cost_a < 0)
	{
		while (cost_info->cost_a < 0)
		{
			rra(data, 1);
			cost_info->cost_a++;
		}
	}
}

void	rotate_b(t_data *data, t_cost *cost_info)
{
	if (cost_info->cost_b > 0)
	{
		while (cost_info->cost_b > 0)
		{
			rb(data, 1);
			cost_info->cost_b--;
		}
	}
	else if (cost_info->cost_b < 0)
	{
		while (cost_info->cost_b < 0)
		{
			rrb(data, 1);
			cost_info->cost_b++;
		}
	}
}
