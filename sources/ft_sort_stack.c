/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:46:40 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/29 23:11:29 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_stack(t_stack **stack_a)
{
	if (!stack_a)
		ft_print_error();

	if (ft_lst_size(*stack_a) == 2 && !(is_sorted(stack_a)))
		ft_sa(stack_a, 0);
	else if (ft_lst_size(*stack_a) == 3)
		ft_sort_three(stack_a);
	else if (ft_lst_size(*stack_a) == 4)
		ft_sort_four(stack_a);
	else if (ft_lst_size(*stack_a) == 5)
		ft_sort_five(stack_a);
	else if (ft_lst_size(*stack_a) > 5 && ft_lst_size(*stack_a) <= 100)
		ft_sort_100(stack_a);
	else
		ft_sort(stack_a);
}

void ft_sort_three(t_stack **stack_a)
{
	if (!is_sorted(stack_a))
	{
		int stack_min = ft_min(*stack_a);
		int stack_max = ft_max(*stack_a);

		if (stack_min == (*stack_a)->nbr && stack_max == (*stack_a)->next->nbr)
		{
			ft_sa(stack_a, 0);
			ft_ra(stack_a, 0);
		}
		else if (stack_min == (*stack_a)->next->next->nbr && stack_max == (*stack_a)->nbr)
		{
			ft_ra(stack_a, 0);
			ft_sa(stack_a, 0);
		}
		else if (stack_min == (*stack_a)->next->nbr && stack_max == (*stack_a)->next->next->nbr)
			ft_sa(stack_a, 0);
		else if (stack_min == (*stack_a)->next->nbr && stack_max == (*stack_a)->nbr)
			ft_ra(stack_a, 0);
		else if (stack_min == (*stack_a)->next->next->nbr && stack_max == (*stack_a)->next->nbr)
			ft_rra(stack_a, 0);
	}

}

void ft_sort_five(t_stack **stack_a)
{
    t_stack *stack_b = NULL;
    int stack_min = ft_min(*stack_a);
    int stack_second_min = ft_second_min(*stack_a);

    while (ft_lst_size(*stack_a) > 3)
    {
        if ((*stack_a)->nbr == stack_min || (*stack_a)->nbr == stack_second_min)
            ft_pb(stack_a, &stack_b, 0);
        else if ((ft_lst_last(*stack_a))->nbr == stack_min
			|| (ft_lst_last(*stack_a))->nbr == stack_second_min
            || (ft_lst_last(*stack_a))->prev->nbr == stack_min
			|| (ft_lst_last(*stack_a))->prev->nbr == stack_second_min)
            ft_rra(stack_a, 0);
        else
            ft_ra(stack_a, 0);
    }

    if (!(is_sorted(stack_a)))
        ft_sort_three(stack_a);

    if (stack_b && stack_b->next && stack_b->nbr < stack_b->next->nbr)
        ft_sb(&stack_b, 0);

    while (stack_b)
        ft_pa(stack_a, &stack_b, 0);
}


void ft_sort_four(t_stack **stack_a)
{
	t_stack *stack_b = NULL;
	int stack_min = ft_min(*stack_a);

	while (ft_lst_size(*stack_a) > 3)
	{
		if ((*stack_a)->nbr == stack_min)
			ft_pb(stack_a, &stack_b, 0);
		else if (ft_lst_last((*stack_a))->nbr == stack_min)
		{
			ft_rra (stack_a, 0);
			ft_pb(stack_a, &stack_b, 0);
		}
		else
			ft_ra(stack_a, 0);
	}

	if (!(is_sorted(stack_a)))
		ft_sort_three(stack_a);

	ft_pa(stack_a, &stack_b, 0);
}


int ft_stack_mean(t_stack **stack)
{
	int stack_sum = 0;
	int stack_size = ft_lst_size(*stack);
	int stack_mean = 0;

	t_stack *tmp;

	tmp = *stack;

	while ((tmp))
	{
		stack_sum += (tmp)->nbr;
		(tmp) = (tmp)->next;
	}

	stack_mean = stack_sum/stack_size;

	return (stack_mean);
}
