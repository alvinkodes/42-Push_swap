/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:11:17 by akok              #+#    #+#             */
/*   Updated: 2025/06/30 09:58:29 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_info *from, t_info *to);

void	pa(t_data *data, int print)
{
	if (push(&data->stack_b, &data->stack_a) == -1)
		return ;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data, int print)
{
	if (push(&data->stack_a, &data->stack_b) == -1)
		return ;
	if (print)
		ft_putstr_fd("pb\n", 1);
}

static int	push(t_info *from, t_info *to)
{
	t_stack	*top;

	if (!from->head)
		return (-1);
	top = from->head;
	from->head = top->next;
	if (from->head != NULL)
		from->head->prev = NULL;
	else
		from->tail = NULL;
	top->next = to->head;
	if (to->head != NULL)
		to->head->prev = top;
	to->head = top;
	if (to->tail == NULL)
		to->tail = top;
	from->size--;
	to->size++;
	return (1);
}
