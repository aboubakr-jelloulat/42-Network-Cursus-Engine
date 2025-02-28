/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:48:18 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/25 20:10:58 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*lstnew(int content)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = content;
	node->index = 0;
	node->next = NULL;
	return (node);
}

void	push_back(t_stack **head, int data)
{
	t_stack	*new_node;
	t_stack	*cur;

	if (!head)
		return ;
	new_node = lstnew(data);
	if (!*head)
	{
		*head = new_node;
	}
	else
	{
		cur = *head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = new_node;
	}
}

bool	long_length(const char *str)
{
	int	i;
	int	len;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	len = 0;
	while (str[i++])
		len++;
	return (len <= 19);
}

int	is_only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
