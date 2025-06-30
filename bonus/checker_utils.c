/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:08:34 by akok              #+#    #+#             */
/*   Updated: 2025/06/30 10:24:06 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_ops(char *line);
static void	execute_ops(char *line, t_data *data);
static void	error_exit(char *line, t_data *data);

void	run_checker(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (check_ops(line) == -1)
			error_exit(line, data);
		execute_ops(line, data);
		free(line);
		line = get_next_line(fd);
	}
}

static int	check_ops(char *line)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "sb\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "ss\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "ra\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rb\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rr\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rra\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "pa\n", 4) == 0)
		return (1);
	if (ft_strncmp(line, "pb\n", 4) == 0)
		return (1);
	return (-1);
}

static void	execute_ops(char *line, t_data *data)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		sa(data, 0);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		sb(data, 0);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		ss(data, 0);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		ra(data, 0);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		rb(data, 0);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rr(data, 0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		rra(data, 0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		rrb(data, 0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(data, 0);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		pa(data, 0);
	else
		pb(data, 0);
}

static void	error_exit(char *line, t_data *data)
{
	ft_putendl_fd("Error", 2);
	free(line);
	ps_lstclear(&data->stack_a.head);
	ps_lstclear(&data->stack_b.head);
	exit(255);
}
