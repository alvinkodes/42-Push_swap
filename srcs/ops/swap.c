/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:11:28 by akok              #+#    #+#             */
/*   Updated: 2025/06/25 17:28:41 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_info *stack);

void	sa(t_data *data)
{
	swap(&data->stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_data *data)
{
	swap(&data->stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_data *data)
{
	swap(&data->stack_a);
	swap(&data->stack_b);
	ft_putstr_fd("ss\n", 1);
}

static void	swap(t_info *stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = first->next;
	third = second->next;
	first->next = second->next;
	first->prev = second;
	if (third)
		third->prev = first;
	second->next = first;
	second->prev = NULL;
	stack->head = second;
	if (stack->tail == second)
		stack->tail = first;
}
