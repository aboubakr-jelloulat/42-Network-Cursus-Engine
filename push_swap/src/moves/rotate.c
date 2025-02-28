/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:35:49 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/11 12:09:19 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*iteration(t_stack *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

bool	rotate(t_stack	**stack)
{
	t_stack	*tmp_head;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	tmp_head = *stack;
	last = iteration(tmp_head);
	*stack = tmp_head->next;
	last->next = tmp_head;
	tmp_head->next = NULL;
	return (true);
}

bool	ra(t_stack **a)
{
	if (!rotate(a))
		return (false);
	ft_putendl_fd("ra", 1);
	return (true);
}

bool	rb(t_stack **b)
{
	if (!rotate(b))
		return (false);
	ft_putendl_fd("rb", 1);
	return (true);
}

bool	rr(t_stack **a, t_stack **b)
{
	if (!rotate(a) || !rotate(b))
		return (false);
	ft_putendl_fd("rr", 1);
	return (true);
}
