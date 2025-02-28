/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajelloul <ajelloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:11:23 by ajelloul          #+#    #+#             */
/*   Updated: 2025/02/25 20:11:12 by ajelloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	fail_push_swap(char *content, int status)
{
	ft_putendl_fd(content, 2);
	exit(status);
}

void	free_2d(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free (str[i]);
		str[i] = NULL;
		i++;
	}
	free (str);
	str = NULL;
}

static int	count_args(int ac, char **av)
{
	char	**split;
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (i < ac)
	{
		if (!av[i][0] || is_only_spaces(av[i]))
			fail_push_swap("Error", 1);
		split = ft_split(av[i], ' ');
		if (!split)
			return (-1);
		j = 0;
		while (split[j])
		{
			count++;
			j++;
		}
		free_2d(split);
		i++;
	}
	return (count);
}

static char	**fill_args(int ac, char **av, int count)
{
	char	**new;
	char	**split;
	int		i;
	int		j;
	int		k;

	new = malloc(sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	i = 0;
	k = 0;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (free_2d(new), NULL);
		j = 0;
		while (split[j])
			new[k++] = split[j++];
		free(split);
		i++;
	}
	new[k] = NULL;
	return (new);
}

char	**parsing_args(int ac, char **av)
{
	int	count;

	count = count_args(ac, av);
	if (count < 0)
	{
		return (NULL);
	}
	return (fill_args(ac, av, count));
}
