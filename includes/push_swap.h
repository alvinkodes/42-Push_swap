/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:30:21 by akok              #+#    #+#             */
/*   Updated: 2025/07/01 16:34:07 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdint.h>

typedef struct s_stack
{
	int				val;
	int				index;
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
int		max_ab(int cost_a, int cost_b);
int		binary_search(int *arr, int val, int size);
int		get_node_pos(t_data *data, int val);
int		get_insert_pos(t_info *stack, int val);
int		cost_to_place(t_data *data, int stack_size, int val);

void	free_2arr(char **arr);
void	turk_sort(t_data *data);
void	sort_three(t_data *data);
void	init_tcost(t_cost *data);
void	init_stack(t_data *data);
void	ps_lstclear(t_stack **lst);
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
void	sort_under_three(t_data *data);
void	free_input(t_data *data, char **arr);
void	assign_index(t_data *data, int **arr);
void	quicksort(int *arr, int low, int high);
void	parse_input(char **input, t_data *data);
void	do_op(t_data *data, t_cost	*cost_info);
void	rotate_a(t_data *data, t_cost *cost_info);
void	rotate_b(t_data *data, t_cost *cost_info);
void	rotate_both(t_data *data, t_cost *cost_info);
void	ps_lstaddback(t_stack **lst, t_data *data, t_stack *new_node);
void	set_min_max(t_data *data, int *min_val, int *max_val);

t_stack	*ps_lstnew(int val);

t_cost	cal_cost(t_stack *node, t_data *data);

#endif