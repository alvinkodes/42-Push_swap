/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:56:59 by akok              #+#    #+#             */
/*   Updated: 2025/07/01 16:20:39 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	execute operations
void	do_op(t_data *data, t_cost	*cost_info)
{
	rotate_both(data, cost_info);
	rotate_a(data, cost_info);
	rotate_b(data, cost_info);
	pa(data, 1);
}
