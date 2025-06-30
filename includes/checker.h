/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:30:21 by akok              #+#    #+#             */
/*   Updated: 2025/06/30 10:20:44 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# define A_TO_B 0
# define B_TO_A 1

# include "libft.h"
# include <stdint.h>

typedef struct s_stack
{
	int				val;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info
{
	t_stack	*head;
	t_stack	*tail;
	int		size;
}	t_info;

typedef struct s_data
{
	t_info	stack_a;
	t_info	stack_b;
}	t_data;

typedef struct s_cost
{
	t_stack	*node;
	int		cost_a;
	int		cost_b;
	int		tot_cost;
}	t_cost;

int		is_sorted(t_data *data);

void	ps_lstaddback(t_stack **lst, t_data *data, t_stack *new_node);
void	ps_lstclear(t_stack **lst);
void	free_2arr(char **arr);
void	parse_input(char **input, t_data *data);
void	pa(t_data *data, int print);
void	pb(t_data *data, int print);
void	sa(t_data *data, int print);
void	sb(t_data *data, int print);
void	ss(t_data *data, int print);
void	ra(t_data *data, int print);
void	rb(t_data *data, int print);
void	rr(t_data *data, int print);
void	rra(t_data *data, int print);
void	rrb(t_data *data, int print);
void	rrr(t_data *data, int print);
void	free_input(t_data *data, char **arr);
void	init_stack(t_data *data);
void	run_checker(int fd, t_data *data);

t_stack	*ps_lstnew(int val);

#endif