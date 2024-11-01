/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_means.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 12:51:36 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/26 16:13:06 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int find_next_memmean1_top(t_stack **stack, int mean1_stack_a)
{
	t_stack *current = NULL;
	t_stack *tail = NULL;
	t_stack *tmp = *stack;
	t_stack *new_node;

	// Create a deep copy of stack
	while (tmp)
	{
		// Allocate memory for a new node
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return INT_MAX; // Handle memory allocation failure

		// Copy the data from the original node
		new_node->nbr = tmp->nbr;
		new_node->next = NULL;

		// Link the new node into the new list
		if (!current)
			current = new_node; // Set the head of the new list
		else
			tail->next = new_node; // Attach to the last node in the new list

		tail = new_node; // Move the tail to the new node

		tmp = tmp->next; // Move to the next node in stack
	}

	// Iterate through the copied stack to find the next member
	tmp = current; // Reset tmp to the head of the copied list
	while (tmp)
	{
		if (tmp->nbr <= mean1_stack_a)
		{
			int result = tmp->nbr;

			// Free the copied list to prevent memory leaks
			while (current)
			{
				tmp = current;
				current = current->next;
				free(tmp);
			}

			return result;
		}
		tmp = tmp->next;
	}

	// Free the copied list to prevent memory leaks
	while (current)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}

	return INT_MAX; // Return INT_MAX if no element is found
}

int find_next_memmean1_bottom(t_stack **stack, int mean1_stack_a)
{
    t_stack *current = NULL;
    t_stack *tail = NULL;
    t_stack *tmp = *stack;
    t_stack *new_node;

    // Create a deep copy of the stack
    while (tmp)
    {
        // Allocate memory for a new node
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return INT_MIN; // Handle memory allocation failure

        // Copy the data from the original node
        new_node->nbr = tmp->nbr;
        new_node->next = NULL;
        new_node->prev = tail; // Link to the previous node

        // Link the new node into the new list
        if (!current)
            current = new_node; // Set the head of the new list
        else
            tail->next = new_node; // Attach to the last node in the new list

        tail = new_node; // Move the tail to the new node

        tmp = tmp->next; // Move to the next node in the original stack
    }

    // Traverse the copied stack from the tail to find the next member
    tmp = tail; // Start from the last node in the copied list
    while (tmp)
    {
        if (tmp->nbr <= mean1_stack_a)
        {
            int result = tmp->nbr;

            // Free the copied list to prevent memory leaks
            while (current)
            {
                tmp = current;
                current = current->next;
                free(tmp);
            }

            return result;
        }
        tmp = tmp->prev; // Move backward in the copied list
    }

    // Free the copied list to prevent memory leaks
    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }

    return INT_MIN; // Return INT_MIN if no element is found
}

int find_next_memmean_top(t_stack **stack, int stack_mean)
{
    t_stack *current = NULL;
    t_stack *tail = NULL;
    t_stack *tmp = *stack;
    t_stack *new_node;

    // Create a deep copy of the stack
    while (tmp)
    {
        // Allocate memory for a new node
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return INT_MAX; // Handle memory allocation failure

        // Copy the data from the original node
        new_node->nbr = tmp->nbr;
        new_node->next = NULL;

        // Link the new node into the new list
        if (!current)
            current = new_node; // Set the head of the new list
        else
            tail->next = new_node; // Attach to the last node in the new list

        tail = new_node; // Move the tail to the new node

        tmp = tmp->next; // Move to the next node in the original stack
    }

    // Iterate through the copied stack to find the next member
    tmp = current; // Reset tmp to the head of the copied list
    while (tmp)
    {
        if (tmp->nbr <= stack_mean)
        {
            int result = tmp->nbr;

            // Free the copied list to prevent memory leaks
            while (current)
            {
                tmp = current;
                current = current->next;
                free(tmp);
            }

            return result;
        }
        tmp = tmp->next;
    }

    // Free the copied list to prevent memory leaks
    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }

    return INT_MAX; // Return -1 if no element is found
}


int find_next_memmean_bottom(t_stack **stack, int stack_mean)
{
    t_stack *current = NULL;
    t_stack *tail = NULL;
    t_stack *tmp = *stack;
    t_stack *new_node;

    // Create a deep copy of the stack
    while (tmp)
    {
        // Allocate memory for a new node
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return INT_MIN; // Handle memory allocation failure

        // Copy the data from the original node
        new_node->nbr = tmp->nbr;
        new_node->next = NULL;
        new_node->prev = tail; // Link to the previous node

        // Link the new node into the new list
        if (!current)
            current = new_node; // Set the head of the new list
        else
            tail->next = new_node; // Attach to the last node in the new list

        tail = new_node; // Move the tail to the new node

        tmp = tmp->next; // Move to the next node in the original stack
    }

    // Traverse the copied stack from the tail to find the next member
    tmp = tail; // Start from the last node in the copied list
    while (tmp)
    {
        if (tmp->nbr <= stack_mean)
        {
            int result = tmp->nbr;

            // Free the copied list to prevent memory leaks
            while (current)
            {
                tmp = current;
                current = current->next;
                free(tmp);
            }

            return result;
        }
        tmp = tmp->prev; // Move backward in the copied list
    }

    // Free the copied list to prevent memory leaks
    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }

    return INT_MIN; // Return -1 if no element is found
}


int find_next_memmean3_top(t_stack **stack, int mean3_stack)
{
    t_stack *current = NULL;
    t_stack *tail = NULL;
    t_stack *tmp = *stack;
    t_stack *new_node;

    // Create a deep copy of the stack
    while (tmp)
    {
        // Allocate memory for a new node
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
            return INT_MAX; // Handle memory allocation failure

        // Copy the data from the original node
        new_node->nbr = tmp->nbr;
        new_node->next = NULL;

        // Link the new node into the new list
        if (!current)
            current = new_node; // Set the head of the new list
        else
            tail->next = new_node; // Attach to the last node in the new list

        tail = new_node; // Move the tail to the new node

        tmp = tmp->next; // Move to the next node in the original stack
    }

    // Iterate through the copied stack to find the next member
    tmp = current; // Reset tmp to the head of the copied list
    while (tmp)
    {
        if (tmp->nbr <= mean3_stack)
        {
            int result = tmp->nbr;

            // Free the copied list to prevent memory leaks
            while (current)
            {
                tmp = current;
                current = current->next;
                free(tmp);
            }

            return result;
        }
        tmp = tmp->next;
    }

    // Free the copied list to prevent memory leaks
    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }

    return INT_MAX; // Return -1 if no element is found
}


int find_next_memmean3_bottom(t_stack **stack, int mean3_stack)
{
    t_stack *current = NULL;
    t_stack *tail = NULL;
    t_stack *tmp = *stack;
    t_stack *new_node;

    // Create a deep copy of the stack
    while (tmp)
    {
        // Allocate memory for a new node
        new_node = malloc(sizeof(t_stack));
        if (!new_node)
        {
            // Free previously allocated nodes in case of failure
            while (current)
            {
                tmp = current;
                current = current->next;
                free(tmp);
            }
            return INT_MIN; // Handle memory allocation failure
        }

        // Copy the data from the original node
        new_node->nbr = tmp->nbr;
        new_node->next = NULL;
        new_node->prev = tail; // Link to the previous node

        // Link the new node into the new list
        if (!current)
            current = new_node; // Set the head of the new list
        else
            tail->next = new_node; // Attach to the last node in the new list

        tail = new_node; // Move the tail to the new node

        tmp = tmp->next; // Move to the next node in the original stack
    }

    // Traverse the copied stack from the tail to find the next member
    tmp = tail; // Start from the last node in the copied list
    while (tmp)
    {
        if (tmp->nbr <= mean3_stack)
        {
            int result = tmp->nbr;

            // Free the copied list to prevent memory leaks
            while (current)
            {
                tmp = current;
                current = current->next;
                free(tmp);
            }

            return result;
        }
        tmp = tmp->prev; // Move backward in the copied list
    }

    // Free the copied list to prevent memory leaks
    while (current)
    {
        tmp = current;
        current = current->next;
        free(tmp);
    }

    return INT_MIN; // Return -1 if no element is found
}

