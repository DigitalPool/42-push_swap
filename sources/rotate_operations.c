/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:14:28 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/29 08:52:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack **a, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while ((last)->next)
		(last) = (last)->next;
	last->next = tmp;
	tmp->next = NULL;

	if (j == 0)
		write(1, "ra\n", 3);

}

void	ft_rb(t_stack **b, int j)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	last = *b;
	while ((last)->next)
		(last) = (last)->next;
	last->next = tmp;
	tmp->next = NULL;

	if (j == 0)
		write(1, "rb\n", 3);

}

void	ft_rr(t_stack **a, t_stack **b, int j)
{
	ft_ra(a, 1);
	ft_rb(b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
}

