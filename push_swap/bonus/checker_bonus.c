/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 09:36:14 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/27 17:51:49 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

static int	is_exist(char *name)
{
	return (ft_strncmp(name, "sa\n", 3) == 0 || ft_strncmp(name, "sb\n", 3) == 0
		|| ft_strncmp(name, "ss\n", 3) == 0 || ft_strncmp(name, "pa\n", 3) == 0
		|| ft_strncmp(name, "pb\n", 3) == 0 || ft_strncmp(name, "ra\n", 3) == 0
		|| ft_strncmp(name, "rb\n", 3) == 0 || ft_strncmp(name, "rr\n", 3) == 0
		|| ft_strncmp(name, "rra\n", 4) == 0 || ft_strncmp(name, "rrb\n", 4) == 0
		|| ft_strncmp(name, "rrr\n", 4) == 0);
}

static void	execute_instructions(t_stack **a, t_stack **b, char *move)
{
	if (ft_strncmp(move, "sa\n", 3) == 0 || ft_strncmp(move, "ss\n", 3) == 0)
		swap(a);
	if (ft_strncmp(move, "sb\n", 3) == 0 || ft_strncmp(move, "ss\n", 3) == 0)
		swap(b);
	if (ft_strncmp(move, "pa\n", 3) == 0)
		push(b, a);
	if (ft_strncmp(move, "pb\n", 3) == 0)
		push(a, b);
	if (ft_strncmp(move, "ra\n", 3) == 0 || ft_strncmp(move, "rr\n", 3) == 0)
		rotate(a);
	if (ft_strncmp(move, "rb\n", 3) == 0 || ft_strncmp(move, "rr\n", 3) == 0)
		rotate(b);
	if (ft_strncmp(move, "rra\n", 4) == 0 || ft_strncmp(move, "rrr\n", 4) == 0)
		reverse_rotate(a);
	if (ft_strncmp(move, "rrb\n", 4) == 0 || ft_strncmp(move, "rrr\n", 4) == 0)
		reverse_rotate(b);
}

static void	read_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (is_exist(line))
			execute_instructions(a, b, line);
		else
		{
			free(line);
			free_stack(a);
			free_stack(b);
			error();
		}
		free(line);
	}
	if (is_sorted(*a, bonus) && !*b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**new;

	a = NULL;
	b = NULL;
	new = NULL;
	if (ac == 1)
		exit(1);
	if (ac >= 2)
		new = parsing_args(ac - 1, av + 1);
	if (!new)
		return (0);
	stack_init(&a, new);
	free_2d(new);
	read_instructions(&a, &b);
	free_stack(&b);
	free_stack(&a);
	return (0);
}
