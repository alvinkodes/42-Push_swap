/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akok <akok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:13:08 by akok              #+#    #+#             */
/*   Updated: 2025/05/20 14:32:56 by akok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_sep(char c, char sep)
{
	return (c == sep);
}

static int	ft_count_word(char const *s, char sep)
{
	int		count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!ft_is_sep(s[i], sep) && (i == 0 || ft_is_sep(s[i - 1], sep)))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_next_word(char **arr, char const *s, char sep, size_t *pos)
{
	size_t	start;
	size_t	end;
	size_t	i;

	start = *pos;
	while (s[start] && ft_is_sep(s[start], sep))
		start++;
	end = start;
	while (s[end] && !ft_is_sep(s[end], sep))
		end++;
	*pos = end;
	*arr = (char *)malloc(end - start + 1);
	if (!(*arr))
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		(*arr)[i] = s[start + i];
		i++;
	}
	(*arr)[i] = '\0';
	return (*arr);
}

static void	ft_free_all(char **arr)
{
	char	**tmp;

	if (!arr)
		return ;
	tmp = arr;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	int		wc;
	char	**arr;
	size_t	pos;
	int		i;

	if (!s)
		return (NULL);
	wc = ft_count_word(s, c);
	arr = (char **)malloc((wc + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	pos = 0;
	while (i < wc)
	{
		if (!ft_next_word(&arr[i], s, c, &pos))
		{
			ft_free_all(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
