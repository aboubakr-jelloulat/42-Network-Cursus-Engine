/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:09:32 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/25 20:12:06 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static t_stack	*bring_biggest_node(t_stack *head)
{
	t_stack	*biggest;

	if (!head)
		return (NULL);
	biggest = head;
	while (head)
	{
		if (head->data > biggest->data)
		{
			biggest = head;
		}
		head = head->next;
	}
	return (biggest);
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = bring_biggest_node(*a);
	if (biggest == *a)
	{
		ra(a);
	}
	else if (biggest == (*a)->next)
	{
		rra(a);
	}
	if ((*a)->data > (*a)->next->data)
	{
		sa(a);
	}
}
