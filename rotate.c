/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:09:59 by akok              #+#    #+#             */
/*   Updated: 2025/06/06 15:28:39 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack);

void	ra(t_list **a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_list **b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", 1);
}

static void	rotate(t_list **stack)
{
	t_list	*new_top;
	t_list	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	new_top = (*stack)->next;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	(*stack)->next = NULL;
	*stack = new_top;
}
