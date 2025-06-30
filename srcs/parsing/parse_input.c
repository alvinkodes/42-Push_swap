/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 10:38:28 by akok              #+#    #+#             */
/*   Updated: 2025/06/30 08:49:18 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_digit(const char *s);
static int	check_dup(t_stack *lst, int val);
static int	check_limit(long val);
static int	is_valid_input(long val, const char *s, t_stack *lst);

void	parse_input(char **input, t_data *data)
{
	size_t	i;
	long	val;
	char	**arr;
	t_stack	*node;

	while (*input)
	{
		arr = ft_split(*input, ' ');
		if (*arr == NULL)
			return (free_input(data, arr));
		i = 0;
		while (arr[i])
		{
			val = ft_atoi(arr[i]);
			if (!is_valid_input(val, arr[i], data->stack_a.head))
				return (free_input(data, arr));
			node = ps_lstnew(val);
			ps_lstaddback(&data->stack_a.head, data, node);
			i++;
		}
		free_2arr(arr);
		input++;
	}
}

static int	is_valid_input(long val, const char *s, t_stack *lst)
{
	return (check_limit(val)
		&& check_digit(s)
		&& check_dup(lst, val));
}

static int	check_limit(long val)
{
	return (val >= INT32_MIN && val <= INT32_MAX);
}

static int	check_dup(t_stack *lst, int val)
{
	while (lst)
	{
		if (lst->val == val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	check_digit(const char *s)
{
	if (*s == '+' || *s == '-')
		s++;
	if (!*s)
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s++))
			return (0);
	}
	return (1);
}
