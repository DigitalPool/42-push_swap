/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_tob_on.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:23:29 by mac               #+#    #+#             */
/*   Updated: 2024/08/29 11:23:50 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void push_tob(t_stack **stack_a, t_stack **stack_b, int mean_value)
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

void push_tob_rot(t_stack **stack_a, t_stack **stack_b, int mean_value)
{
	while ((*stack_a) && (!is_sorted(stack_a)) && (ft_min(*stack_a) <= mean_value) && (ft_lst_size(*stack_a) > 3))
	{
		if ((*stack_a)->nbr <= mean_value)
		{
			ft_pb(stack_a, stack_b, 0);
			ft_rb(stack_b, 0);
		}
		else if ((ft_lst_last(*stack_a))->nbr <= mean_value)
		{
			ft_rra(stack_a, 0);
			ft_pb(stack_a, stack_b, 0);
			ft_rb(stack_b, 0);
		}
		else if ((move_count_ra(stack_a, find_next_memmean_top(stack_a, mean_value)))
			< (move_count_rra(stack_a, find_next_memmean_bottom(stack_a, mean_value))))
		{
			if (find_next_memmean_top(stack_a, mean_value) != (*stack_a)->nbr)
				ft_ra(stack_a, 0);
			else
			{
				ft_pb(stack_a, stack_b, 0);
				ft_rb(stack_b, 0);
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
				ft_rb(stack_b, 0);
			}
		}
		else
			ft_ra(stack_a, 0);
	}
}
