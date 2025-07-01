/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:47:01 by akok              #+#    #+#             */
/*   Updated: 2025/07/01 13:45:11 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input(t_data *data, char **arr)
{
	free_2arr(arr);
	ps_lstclear(&data->stack_a.head);
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(int *arr, int low, int high)
{
	int	i;
	int	j;
	int	pivot;

	pivot = arr[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (arr[i] <= pivot && i <= high - 1)
			i++;
		while (arr[j] >= pivot && j >= low + 1)
			j--;
		if (i < j)
			swap(&arr[i], &arr[j]);
	}
	swap(&arr[low], &arr[j]);
	return (j);
}

void	quicksort(int *arr, int low, int high)
{
	int	index;

	if (low < high)
	{
		index = partition(arr, low, high);
		quicksort(arr, low, index - 1);
		quicksort(arr, index + 1, high);
	}
}

int	binary_search(int *arr, int val, int size)
{
	int	low;
	int	mid;
	int	high;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (arr[mid] > val)
			high = mid - 1;
		else if (arr[mid] < val)
			low = mid + 1;
		else
			return (mid);
	}
	return (-1);
}
