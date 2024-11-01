/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:59:49 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/29 09:54:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//Here we chech which number of the quatile is close to the top or the bottom
//then we push. After pushing all to stack_b, the top quartile of stack_b would
//would be filled with the highest numbers down the stack. we would then start
//pushing the big numbers into stack_a quartile by quartile, and then sorting them
//but also noting the move counts to see the cheapest moves.


void pusha_tob(t_stack **stack_a, t_stack **stack_b, int mean_value)
{
	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_min(*stack_a) <= mean_value) && (ft_lst_size(*stack_a) > 3))
	{
		if ((*stack_a)->nbr <= mean_value)
		{
			ft_pb(stack_a, stack_b, 0);
		}
		else if ((ft_lst_last(*stack_a))->nbr <= mean_value)
		{
			ft_rra(stack_a, 0);
			ft_pb(stack_a, stack_b, 0);
		}
		else if ((move_count_ra(stack_a, find_next_memmean_top(stack_a, mean_value)))
			< (move_count_rra(stack_a, find_next_memmean_bottom(stack_a, mean_value))))
		{
			if (find_next_memmean_top(stack_a, mean_value) != (*stack_a)->nbr)
				ft_ra(stack_a, 0);
			else
			{
				ft_pb(stack_a, stack_b, 0);
			}
		}
		else if ((move_count_ra(stack_a, find_next_memmean_top(stack_a, mean_value)))
			> (move_count_rra(stack_a, find_next_memmean_bottom(stack_a, mean_value))))
		{
			if (find_next_memmean_bottom(stack_a, mean_value) != (*stack_a)->nbr)
				ft_rra(stack_a, 0);
			else
			{
				ft_pb(stack_a, stack_b, 0);
			}
		}
		else
			ft_ra(stack_a, 0);
	}
}

void	ft_sort_100(t_stack **stack_a)
{

	t_stack	**stack_b;
	int		mean1_stack = ft_mean1_stack(stack_a);
	int		mean3_stack = ft_mean3_stack(stack_a);
	// int		mean5_stack = ft_mean5_stack(stack_a);
	int		mean7_stack = ft_mean7_stack(stack_a);
	// int		mean9_stack = ft_mean9_stack(stack_a);
	int		mean11_stack = ft_mean11_stack(stack_a);
	// int		mean13_stack = ft_mean13_stack(stack_a);
	int		mean15_stack = ft_mean15_stack(stack_a);
	int		stack_max = ft_max((*stack_a));
	int		stack_min = ft_min((*stack_a));

	stack_b = (t_stack **)malloc(sizeof(t_stack));

	pusha_tob (stack_a, stack_b, mean1_stack);
	pusha_tob (stack_a, stack_b, mean3_stack);
	// pusha_tob (stack_a, stack_b, mean5_stack);
	pusha_tob (stack_a, stack_b, mean7_stack);
	// pusha_tob (stack_a, stack_b, mean9_stack);
	pusha_tob (stack_a, stack_b, mean11_stack);
	// pusha_tob (stack_a, stack_b, mean13_stack);
	pusha_tob (stack_a, stack_b, mean15_stack);

	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_lst_size(*stack_a) > 3))
	{
		if ((*stack_a)->nbr == stack_max)
			ft_ra(stack_a, 0);
		else
			ft_pb(stack_a, stack_b, 0);
	}
	ft_sort_three(stack_a);

	while ((*stack_b))
	{
		if ((*stack_b)->nbr > (*stack_a)->nbr)
			ft_ra(stack_a, 0);
		if (((*stack_b)->nbr < ft_lst_last(*stack_a)->nbr) && (ft_lst_last(*stack_a)->nbr < (*stack_a)->nbr))
			ft_rra(stack_a, 0);
		else if ((*stack_b)->nbr < (*stack_a)->nbr)
			ft_pa(stack_a, stack_b, 0);
	}

	while (!(is_sorted (stack_a)))
	{
		if (move_count_ra(stack_a, stack_max) < move_count_rra(stack_a, stack_min))
			ft_ra(stack_a, 0);
		else
			ft_rra(stack_a, 0);
	}
}

