/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 15:37:37 by akok              #+#    #+#             */
/*   Updated: 2025/06/27 15:53:54 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_between_desc(int cur_val, int next_val, int val)
{
	return (val < cur_val && val > next_val);
}

int	is_between_ascd(int cur_val, int next_val, int val)
{
	return (val > cur_val && val < next_val);
}

int	max_ab(int cost_a, int cost_b)
{
	if (cost_a < 0)
		cost_a = -cost_a;
	if (cost_b < 0)
		cost_b = -cost_b;
	if (cost_a >= cost_b)
		return (cost_a);
	return (cost_b);
}
