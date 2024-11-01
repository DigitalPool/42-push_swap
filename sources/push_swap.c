/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:51:42 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/29 05:25:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack *stack)
{
	if (!stack)
		ft_print_error();

	t_stack *tmp = stack;

	while (tmp)
	{
		printf("%ld\n", tmp->nbr);
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;

	// Initialize the stack with input arguments
	stack_a = ft_get_stack(argc, argv);

	// Check for errors: empty stack, duplicates, etc.
	if (!stack_a || ft_check_duplicate(stack_a))
	{
		ft_free_stack(&stack_a);
		ft_print_error();
		return (1);  // Exit with error code
	}

	// Print the stack before sorting
	// printf("Stack before sorting:\n");
	// print_stack(stack_a);

	// Sort the stack if it's not already sorted
	if (!is_sorted(&stack_a))
		ft_sort_stack(&stack_a);

	// Print the stack after sorting
	// printf("Stack after sorting:\n");
	// print_stack(stack_a);

	// Free the stack memory
	ft_free_stack(&stack_a);
	return (0);
}
