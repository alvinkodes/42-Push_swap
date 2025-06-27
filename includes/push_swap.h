/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:30:21 by akok              #+#    #+#             */
/*   Updated: 2025/06/27 16:08:43 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int		is_between_desc(int cur_val, int next_val, int val);
int		is_between_ascd(int cur_val, int next_val, int val);
int		max_ab(int cost_a, int cost_b);
int		get_node_pos(t_data *data, int val, int move_dir);
int		get_insert_pos(t_info *stack, int val, int (*cmp)(int, int, int));
int		is_between_desc(int cur_val, int next_val, int val);
int		is_between_ascd(int cur_val, int next_val, int val);
int		max_ab(int cost_a, int cost_b);
int		cost_to_place(t_data *data, int stack_size, int val, int move_dir);

void	ps_lstaddback(t_stack **lst, t_data *data, t_stack *new_node);
void	ps_lstclear(t_stack **lst);
void	free_2arr(char **arr);
void	parse_input(char **input, t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	turk_sort(t_data *data);
void	sort_three(t_data *data);;
void	sort_under_three(t_data *data);
void	do_op(t_data *data, t_cost	*cost_info);
void	rotate_a(t_data *data, t_cost *cost_info);
void	init_tcost(t_cost *data);
void	set_min_max(t_data *data, int *min_val, int *max_val, int move_dir);
void	rotate_both(t_data *data, t_cost *cost_info);
void	rotate_a(t_data *data, t_cost *cost_info);
void	rotate_b(t_data *data, t_cost *cost_info);

t_stack	*ps_lstnew(int val);

t_cost	cal_cost(t_stack *node, t_data *data);

#endif