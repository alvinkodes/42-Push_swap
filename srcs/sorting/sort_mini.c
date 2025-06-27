/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:13:10 by akok              #+#    #+#             */
/*   Updated: 2025/06/27 15:51:07 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_data *data);

void	sort_under_three(t_data *data)
{
	if (data->stack_a.size == 1)
		return ;
	else if (data->stack_a.size == 2)
		return (sort_two(data));
	else
		return (sort_three(data));
}

static void	sort_two(t_data *data)
{
	t_stack	*top;
	t_stack	*bot;

	top = data->stack_a.head;
	bot = top->next;
	if (top->val < bot->val)
		return ;
	sa(data);
}

void	sort_three(t_data *data)
{
	int	top_val;
	int	mid_val;
	int	bot_val;

	top_val = data->stack_a.head->val;
	mid_val = data->stack_a.head->next->val;
	bot_val = data->stack_a.head->next->next->val;
	if (top_val > mid_val && top_val < bot_val)
		sa(data);
	else if (top_val < mid_val && mid_val > bot_val && top_val < bot_val)
	{
		rra(data);
		sa(data);
	}
	else if (top_val < mid_val && top_val > bot_val)
		rra(data);
	else if (top_val > mid_val && mid_val > bot_val)
	{
		sa(data);
		rra(data);
	}
	else if (top_val > mid_val && mid_val < bot_val && top_val > bot_val)
		ra(data);
}
