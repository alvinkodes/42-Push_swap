/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:09:13 by akok              #+#    #+#             */
/*   Updated: 2025/06/07 13:19:28 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
/*
void turk_sort(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return ;
}*/

int	main(int ac, char **av)
{
	t_list	*stack_a;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	parse_input(av + 1, &stack_a);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	//turk_sort(&stack_a);
	ft_printlst(stack_a, print_int);
	ft_lstclear(&stack_a, dummy_free);
	return (0);
}
