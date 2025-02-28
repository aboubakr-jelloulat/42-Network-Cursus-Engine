/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:28:51 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/15 10:38:30 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	*get_copy(t_stack *stack, int size)
{
	int	*copy;
	int	u;

	u = 0;
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	while (u < size)
	{
		copy[u] = stack->data;
		stack = stack->next;
		u++;
	}
	return (copy);
}

static int	*sort_array(t_stack *stack, int len)
{
	int	*arr;
	int	i;
	int	j;
	int	tmp;

	arr = get_copy(stack, len);
	i = 1;
	while (i <= len)
	{
		j = 0;
		while (j < len - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	assigning_indexes(t_stack **stack, int len)
{
	t_stack	*tmp_head;
	int		*sort_arr;
	int		i;

	tmp_head = (*stack);
	sort_arr = sort_array(*stack, len);
	while (tmp_head)
	{
		i = 0;
		while (i < len)
		{
			if (sort_arr[i] == tmp_head->data)
			{
				tmp_head->index = i;
				break ;
			}
			i++;
		}
		tmp_head = tmp_head->next;
	}
	free (sort_arr);
	sort_arr = NULL;
}
