/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:09:59 by akok              #+#    #+#             */
/*   Updated: 2025/06/30 09:59:11 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_info *stack);

void	ra(t_data *data, int print)
{
	rotate(&data->stack_a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_data *data, int print)
{
	rotate(&data->stack_b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_data *data, int print)
{
	rotate(&data->stack_a);
	rotate(&data->stack_b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}

static void	rotate(t_info *stack)
{
	t_stack	*top;
	t_stack	*bot;

	if (!stack->head || !stack->head->next)
		return ;
	top = stack->head;
	stack->head = top->next;
	stack->head->prev = NULL;
	bot = stack->tail;
	bot->next = top;
	top->prev = bot;
	stack->tail = top;
	stack->tail->next = NULL;
}
