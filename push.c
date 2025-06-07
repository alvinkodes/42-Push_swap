/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:11:17 by akok              #+#    #+#             */
/*   Updated: 2025/06/06 14:53:09 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	push(t_list **from, t_list **to);

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_putstr_fd("pb\n", 1);
}

static void	push(t_list **from, t_list **to)
{
	t_list	*new_from_top;

	if (!from || !to || !*from)
		return ;
	new_from_top = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = new_from_top;
}
