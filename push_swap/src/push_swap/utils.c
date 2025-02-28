/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 11:12:35 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/15 13:30:01 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *stack, t_part part)
{
	if (!stack)
	{
		return (0);
	}
	if (part == mandatory)
	{
		if (lstsize(stack) < 2)
		{
			exit(0);
		}
	}
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	lstsize(t_stack *head)
{
	int	counter;

	if (!head)
		return (0);
	counter = 0;
	while (head)
	{
		counter++;
		head = head->next;
	}
	return (counter);
}
