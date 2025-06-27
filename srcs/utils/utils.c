/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:04:57 by akok              #+#    #+#             */
/*   Updated: 2025/06/27 15:46:19 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstnew(int val)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->val = val;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ps_lstaddback(t_stack **lst, t_data *data, t_stack *new_node)
{
	if (*lst == NULL)
	{
		*lst = new_node;
		data->stack_a.head = new_node;
		data->stack_a.tail = new_node;
		data->stack_a.size++;
		return ;
	}
	new_node->prev = data->stack_a.tail;
	data->stack_a.tail->next = new_node;
	data->stack_a.tail = new_node;
	data->stack_a.size++;
}

void	ps_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst)
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		free(tmp);
		tmp = *lst;
	}
	*lst = NULL;
}

int	is_sorted(t_data *data)
{
	t_stack	*cur;
	int		max_so_far;

	cur = data->stack_a.head;
	max_so_far = cur->val;
	while (cur)
	{
		if (cur->val < max_so_far)
			return (0);
		max_so_far = cur->val;
		cur = cur->next;
	}
	ps_lstclear(&data->stack_a.head);
	ps_lstclear(&data->stack_b.head);
	return (1);
}

void	free_2arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
