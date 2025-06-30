/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:43:26 by akok              #+#    #+#             */
/*   Updated: 2025/06/30 09:58:13 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_info *stack);

void	rra(t_data *data, int print)
{
	reverse_rotate(&data->stack_a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_data *data, int print)
{
	reverse_rotate(&data->stack_b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_data *data, int print)
{
	reverse_rotate(&data->stack_a);
	reverse_rotate(&data->stack_b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}

static void	reverse_rotate(t_info *stack)
{
	t_stack	*bot;

	if (!stack->head || !stack->head->next)
		return ;
	bot = stack->tail;
	stack->tail = bot->prev;
	stack->tail->next = NULL;
	bot->next = stack->head;
	stack->head->prev = bot;
	stack->head = bot;
	bot->prev = NULL;
}
