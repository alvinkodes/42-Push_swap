/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 11:19:11 by akok              #+#    #+#             */
/*   Updated: 2025/06/07 13:52:38 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_digit(const char *s);
static int	check_dup(t_list *lst, int val);
static int	check_limit(long val);
static int	is_valid_input(long val, const char *s, t_list *lst);

void	parse_input(char **input, t_list **lst)
{
	long	val;
	char	**arr;
	size_t	i;
	t_list	*node;

	while (*input)
	{
		arr = ft_split(*input, ' ');
		i = 0;
		while (arr[i])
		{
			val = ft_atoi(arr[i]);
			if (!is_valid_input(val, arr[i], *lst))
			{
				ft_free_all(arr);
				ft_lstclear(lst, dummy_free);
				return ;
			}
			node = ft_lstnew((void *)(intptr_t)val);
			ft_lstadd_back(lst, node);
			i++;
		}
		ft_free_all(arr);
		input++;
	}
}

static int	is_valid_input(long val, const char *s, t_list *lst)
{
	return (check_limit(val)
		&& check_digit(s)
		&& check_dup(lst, val));
}

static int	check_limit(long val)
{
	return (val >= INT32_MIN && val <= INT32_MAX);
}

static int	check_dup(t_list *lst, int val)
{
	while (lst)
	{
		if ((int)(intptr_t)lst->content == val)
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
