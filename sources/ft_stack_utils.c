/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:00:34 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/26 17:09:40 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_min(t_stack *stack_a)
{
	int		i;

	if (!stack_a)  // Check if stack_a is NULL
	{
		// Handle the error, return a special value, or exit
		// Here, returning INT_MAX to signify an error
		return (INT_MAX);
	}

	i = stack_a->nbr;
	while (stack_a)
	{
		if (stack_a->nbr < i)
			i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (i);
}

int	ft_max(t_stack *stack_a)
{
	int		i;

	if (!stack_a)  // Check if stack_a is NULL
	{
		// Handle the error, return a special value, or exit
		// Here, returning INT_MIN to signify an error
		return (INT_MIN);
	}

	i = stack_a->nbr;
	while (stack_a)
	{
		if (stack_a->nbr > i)
			i = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (i);
}

t_stack *ft_lst_last(t_stack *lst)
{
	if (lst == NULL)
		return NULL;

	while (lst->next != NULL)
		lst = lst->next;

	return lst;
}

int ft_lst_size(t_stack *lst)
{
	t_stack *tmp;
	int i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
int ft_second_min(t_stack *stack_a)
{
	int min;
	int second_min;

	if (!stack_a || !stack_a->next)
		return (0);

	min = ft_min(stack_a);
	second_min = INT_MAX;
	while (stack_a)
	{
		if (stack_a->nbr > min && stack_a->nbr < second_min)
			second_min = stack_a->nbr;
		stack_a = stack_a->next;
	}

	// printf("second min:\n");
	// printf ("%d\n", second_min);

	return (second_min);
}
