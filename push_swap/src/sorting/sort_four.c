/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:57:44 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/10 09:17:47 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_index(t_stack *head)
{
	int	min_pos;
	int	current_pos;
	int	min_value;

	min_pos = 0;
	current_pos = 0;
	min_value = head->data;
	while (head)
	{
		if (head->data < min_value)
		{
			min_value = head->data;
			min_pos = current_pos;
		}
		head = head->next;
		current_pos++;
	}
	return (min_pos);
}

void	shift_min_to_front(t_stack **a)
{
	int	len;
	int	min_position;

	min_position = find_min_index(*a);
	len = lstsize(*a);
	if (min_position <= len / 2)
		while (min_position--)
			ra(a);
	else
		while (min_position++ < len)
			rra(a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	shift_min_to_front(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}
