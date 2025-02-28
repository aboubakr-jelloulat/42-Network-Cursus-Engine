/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:37:44 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/09 12:14:50 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp_head;
	t_stack	*last;
	t_stack	*before_last;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	tmp_head = *stack;
	last = iteration(tmp_head);
	before_last = tmp_head;
	while (before_last->next != last)
		before_last = before_last->next;
	before_last->next = NULL;
	last->next = tmp_head;
	*stack = last;
	return (true);
}

bool	rra(t_stack **a)
{
	if (!reverse_rotate(a))
		return (false);
	ft_putendl_fd("rra", 1);
	return (true);
}

bool	rrb(t_stack **b)
{
	if (!reverse_rotate(b))
		return (false);
	ft_putendl_fd("rrb", 1);
	return (true);
}

bool	rrr(t_stack **a, t_stack **b)
{
	if (!reverse_rotate(a) || !reverse_rotate(b))
		return (false);
	ft_putendl_fd("rrr", 1);
	return (true);
}
