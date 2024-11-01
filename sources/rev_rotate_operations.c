/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:14:32 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/17 12:41:39 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rra(t_stack **a, int j)
{
	t_stack	*tmp;
	t_stack	*second_last;

	if (!*a || !(*a)->next)
		return ;

	second_last = *a;
	while ((second_last)->next->next)
	{
		second_last = second_last->next;
	}
	tmp = second_last->next;
	second_last->next = NULL;
	tmp->next = *a;
	*a = tmp;

	if (j == 0)
		write(1, "rra\n", 4);
}

void ft_rrb(t_stack **b, int j)
{
	t_stack	*tmp;
	t_stack	*second_last;

	if (!*b || !(*b)->next)
		return ;

	second_last = *b;
	while ((second_last)->next->next)
	{
		second_last = second_last->next;
	}
	tmp = second_last->next;
	second_last->next = NULL;
	tmp->next = *b;
	*b = tmp;

	if (j == 0)
		write(1, "rra\n", 4);
}

void	ft_rrr(t_stack **a, t_stack **b, int j)
{
	ft_rra(a, 1);
	ft_rrb(b, 1);
	if (j == 0)
		write(1, "rrr\n", 4);
}
