/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_args_to_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:53:41 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/25 17:21:47 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_from_back(t_stack **stack, t_stack *stack_new)
{
	t_stack *last;

	if (!stack || !stack_new)
		return;

	if (*stack == NULL)
	{
		*stack = stack_new;
	}
	else
	{
		last = ft_lst_last(*stack);
		if (last)
		{
			last->next = stack_new;
			stack_new->prev = last;
		}
	}
}

void ft_add_args_to_stack(char **argv, t_stack **stack_a)
{
	long	i;

	i = 1;
	while (argv[i] != NULL)
	{
		add_from_back (stack_a, ft_create_new_node(ft_atoi_stack(argv[i])));
		i++;
	}
}
