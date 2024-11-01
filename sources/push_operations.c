/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 19:18:11 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/25 19:41:48 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pa(t_stack **a, t_stack **b, int j)
{
	t_stack *tmp;

	if (!*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next =tmp;
	if (j == 0)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b, int j)
{
	t_stack *tmp;

	if (!a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	if (j == 0)
		write (1, "pb\n", 3);
}
