/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_counts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:37:30 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/29 11:19:07 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int move_count_ra(t_stack **stack_a, int target)
{
	int count = 0;
	t_stack *current = NULL;
	t_stack *tail = NULL;
	t_stack *tmp = *stack_a;
	t_stack *new_node;

	// Create a deep copy of stack_a
	while (tmp)
	{
		// Allocate memory for a new node
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return -1; // Handle memory allocation failure

		// Copy the data from the original node
		new_node->nbr = tmp->nbr;
		new_node->next = NULL;

		// Link the new node into the new list
		if (!current)
			current = new_node; // Set the head of the new list
		else
			tail->next = new_node; // Attach to the last node in the new list

		tail = new_node; // Move the tail to the new node

		tmp = tmp->next; // Move to the next node in stack_a
	}

	// Iterate through the copied stack to find the target
	while (current && current->nbr != target)
	{
		count++;
		current = current->next;
	}

	// Free the copied list to prevent memory leaks
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}

	return count;
}

int move_count_rra(t_stack **stack_a, int target)
{
	int count = 0;
	int total_elements = 0;
	t_stack *current = NULL;
	t_stack *tail = NULL;
	t_stack *tmp = *stack_a;
	t_stack *new_node;

	// Create a deep copy of stack_a
	while (tmp)
	{
		// Allocate memory for a new node
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return -1; // Handle memory allocation failure

		// Copy the data from the original node
		new_node->nbr = tmp->nbr;
		new_node->next = NULL;

		// Link the new node into the new list
		if (!current)
			current = new_node; // Set the head of the new list
		else
			tail->next = new_node; // Attach to the last node in the new list

		tail = new_node; // Move the tail to the new node

		tmp = tmp->next; // Move to the next node in stack_a

		// Increment the total element count
		total_elements++;
	}

	// Iterate through the copied stack to find the target
	tmp = current; // Reset tmp to the head of the copied list
	while (tmp && tmp->nbr != target)
	{
		count++;
		tmp = tmp->next;
	}

	// Free the copied list to prevent memory leaks
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}

	// The number of reverse rotations needed is total elements minus the forward rotations
	return (total_elements - count);
}

int move_count_rbpa(t_stack **stack_b, int target)
{
	int count = 0;
	t_stack *(*current) = stack_b;

	while ((*current) && (*current)->nbr != target)
	{
		count++;
		(*current) = (*current)->next;
	}

	// Add 1 to the count to account for the `pa` operation
	return (count + 1);
}

int move_count_rrbpa(t_stack **stack_b, int target)
{
	int count = 0;
	t_stack *(*current) = stack_b;

	int total_elements = ft_lst_size(*stack_b);

	while ((*current) && (*current)->nbr != target)
	{
		(*current) = (*current)->next;
		count++;
	}

	// Add 1 to the count to account for the `pa` operation
	return ((total_elements - count) + 1);
}

int find_next_max_top(t_stack **stack)
{
	if (!stack)
		return -1; // Handle empty stack case

	int max_value = (*stack)->nbr;
	t_stack **current = &(*stack)->next;

	while ((*current))
	{
		if ((*current)->nbr > max_value)
			max_value = (*current)->nbr;
		(*current) = (*current)->next;
	}

	return max_value;
}

int find_next_min_bottom(t_stack **stack)
{
	if (!stack)
		return -1; // Handle empty stack case

	t_stack **current = stack;
	int min_value = (*stack)->nbr;

	// Traverse to the end of the stack
	while ((*current)->next)
	{
		(*current) = (*current)->next;
	}

	// Now traverse backwards (from bottom to top)
	while ((*current))
	{
		if ((*current)->nbr < min_value)
			min_value = (*current)->nbr;
		(*current) = (*current)->prev; // Assuming doubly linked list for easy reverse traversal
	}

	return min_value;
}

int move_count_ra_stack(t_stack **stack)
{
	t_stack **current = stack;
	int count = 0;

	while ((*current) && (*current)->next)
	{
		if ((*current)->nbr > (*current)->next->nbr)
			return count + 1; // The number of rotations needed to bring the smallest element to the top
		count++;
		(*current) = (*current)->next;
	}

	return 0; // Stack is already sorted or only one element
}

int move_count_rra_stack(t_stack **stack)
{
	t_stack **current = stack;
	int count = 0;

	// Move to the last element
	while (*current && (*current)->next)
	{
		(*current) = (*current)->next;
	}

	// Traverse backwards, counting until we reach the sorted condition
	while (current && (*current)->prev)
	{
		if ((*current)->nbr < (*current)->prev->nbr)
			return count + 1; // The number of reverse rotations needed to bring the largest element to the top
		count++;
		(*current) = (*current)->prev;
	}

	return 0; // Stack is already sorted or only one element
}

