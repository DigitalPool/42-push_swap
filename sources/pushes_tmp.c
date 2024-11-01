
#include "../includes/push_swap.h"



t_stack *deep_copy_stack(t_stack *original) {
    if (original == NULL) return NULL;

    // Allocate memory for the new stack node
    t_stack *copy = malloc(sizeof(t_stack));
    if (!copy) return NULL; // Handle memory allocation failure

    // Copy the data from the original node
    copy->nbr = original->nbr;
    copy->prev = NULL;

    // Copy the rest of the stack recursively or iteratively
    t_stack *current_orig = original->next;
    t_stack *current_copy = copy;
    while (current_orig != NULL) {
        // Allocate memory for the next node in the copy
        current_copy->next = malloc(sizeof(t_stack));
        if (!current_copy->next) return NULL; // Handle memory allocation failure

        // Copy the data and link the new node
        current_copy->next->nbr = current_orig->nbr;
        current_copy->next->prev = current_copy;

        // Move to the next node
        current_copy = current_copy->next;
        current_orig = current_orig->next;
    }
    current_copy->next = NULL; // Terminate the new stack

    return copy;
}



int pushb_top_tmp(t_stack **stack_a, t_stack **stack_b)
{
    int move_count = 0; // Initialize move counter

    // Create deep copies of stack_a and stack_b
    t_stack *tmp_a = deep_copy_stack(*stack_a);
    t_stack *tmp_b = deep_copy_stack(*stack_b);

    if (tmp_b->nbr > tmp_a->nbr)
    {
        while (tmp_b->nbr > tmp_a->nbr)
        {
            ft_ra(&tmp_a, 1); // Rotate the copied stack
            move_count++;
            tmp_a = tmp_a->next; // Update tmp_a after rotation
        }
        ft_pa(&tmp_a, &tmp_b, 1); // Push on copied stack
        move_count++; // Increment move counter
    }
    // else if (tmp_b->nbr < tmp_a->nbr
    //     && tmp_b->nbr < ft_lst_last(tmp_a)->nbr
    //     && tmp_b->nbr < ft_lst_last(tmp_a)->prev->nbr)
    // {
    //     while (tmp_b->nbr < ft_lst_last(tmp_a)->nbr)
    //     {
    //         ft_rra(&tmp_a, 1); // Reverse rotate the copied stack
    //         move_count++; // Increment move counter
    //         tmp_a = ft_lst_last(tmp_a); // Update tmp_a after reverse rotation
    //     }
    //     ft_pa(&tmp_a, &tmp_b, 1); // Push on copied stack
    //     move_count++; // Increment move counter
    // }
    else if (tmp_b->nbr < tmp_a->nbr
        && tmp_b->nbr < ft_lst_last(tmp_a)->nbr
        && tmp_b->nbr > ft_lst_last(tmp_a)->prev->nbr)
    {
        ft_rra(&tmp_a, 1); // Reverse rotate the copied stack
        move_count++; // Increment move counter
        ft_pa(&tmp_a, &tmp_b, 1); // Push on copied stack
        move_count++; // Increment move counter
    }
    else if (tmp_b->nbr < tmp_a->nbr
        && tmp_b->nbr > ft_lst_last(tmp_a)->nbr
        && tmp_b->nbr > ft_lst_last(tmp_a)->prev->nbr)
    {
        ft_pa(&tmp_a, &tmp_b, 1); // Push on copied stack
        move_count++; // Increment move counter
    }

    // Free the deep copies to avoid memory leaks
    ft_free_stack(&tmp_a);
    ft_free_stack(&tmp_b);

	if ((move_count) >= 1)
    	return move_count; // Return the total number of moves
	else
		return (INT_MAX);
}




int pushb_top2_tmp(t_stack **stack_a, t_stack **stack_b)
{
    int move_count = 0; // Initialize the move counter

    // Create deep copies of stack_a and stack_b
    t_stack *tmp_a = deep_copy_stack(*stack_a);
    t_stack *tmp_b = deep_copy_stack(*stack_b);

    if (tmp_b->next->nbr > tmp_a->nbr)
    {
        ft_rr(&tmp_a, &tmp_b, 1);
        move_count++; // Increment move counter

        while (tmp_b->nbr > tmp_a->nbr)
        {
            ft_ra(&tmp_a, 1);
            move_count++;
            tmp_a = tmp_a->next; // Update tmp_a after rotation
        }
        ft_pa(&tmp_a, &tmp_b, 1);
        move_count++; // Increment move counter
    }
    // else if (tmp_b->next->nbr < tmp_a->nbr
    //     && tmp_b->next->nbr < ft_lst_last(tmp_a)->nbr
    //     && tmp_b->next->nbr < ft_lst_last(tmp_a)->prev->nbr)
    // {
    //     ft_rb(&tmp_b, 1);
    //     move_count++; // Increment move counter

    //     ft_rra(&tmp_a, 1);
    //     move_count++; // Increment move counter
    //     ft_rra(&tmp_a, 1);
    //     move_count++; // Increment move counter

    //     while (tmp_b->nbr < ft_lst_last(tmp_a)->nbr)
    //     {
    //         ft_rra(&tmp_a, 1);
    //         move_count++; // Increment move counter
    //         tmp_a = ft_lst_last(tmp_a); // Update tmp_a after reverse rotation
    //     }
    //     ft_pa(&tmp_a, &tmp_b, 1);
    //     move_count++; // Increment move counter
    // }
    else if (tmp_b->next->nbr < tmp_a->nbr
        && tmp_b->next->nbr < ft_lst_last(tmp_a)->nbr
        && tmp_b->next->nbr > ft_lst_last(tmp_a)->prev->nbr)
    {
        ft_rb(&tmp_b, 1);
        move_count++; // Increment move counter

        ft_rra(&tmp_a, 1);
        move_count++; // Increment move counter
        ft_pa(&tmp_a, &tmp_b, 1);
        move_count++; // Increment move counter
    }
    else if (tmp_b->next->nbr < tmp_a->nbr
        && tmp_b->next->nbr > ft_lst_last(tmp_a)->nbr
        && tmp_b->next->nbr > ft_lst_last(tmp_a)->prev->nbr)
    {
        ft_rb(&tmp_b, 1);
        move_count++; // Increment move counter

        ft_pa(&tmp_a, &tmp_b, 1);
        move_count++; // Increment move counter
    }

    // Free the deep copies to avoid memory leaks
    ft_free_stack(&tmp_a);
    ft_free_stack(&tmp_b);

	if ((move_count) >= 1)
    	return move_count; // Return the total number of moves
	else
		return (INT_MAX);
}


int pushb_bot_tmp(t_stack **stack_a, t_stack **stack_b)
{
    int move_count = 0; // Initialize the move counter

    // Create deep copies of stack_a and stack_b
    t_stack *tmp_a = deep_copy_stack(*stack_a);
    t_stack *tmp_b = deep_copy_stack(*stack_b);

    if (ft_lst_last(tmp_b)->nbr > tmp_a->nbr)
    {
        ft_rrb(&tmp_b, 1);
        move_count++; // Increment move counter
        tmp_b = *stack_b;

        while (tmp_b->nbr > tmp_a->nbr)
        {
            ft_ra(&tmp_a, 1);
            move_count++; // Increment move counter
            tmp_a = tmp_a->next; // Update tmp_a after rotation
        }
        ft_pa(&tmp_a, &tmp_b, 1);
        move_count++; // Increment move counter
    }
    // else if (ft_lst_last(tmp_b)->nbr < tmp_a->nbr
    //     && ft_lst_last(tmp_b)->nbr < ft_lst_last(tmp_a)->nbr
    //     && ft_lst_last(tmp_b)->nbr < ft_lst_last(tmp_a)->prev->nbr)
    // {
    //     ft_rrr(&tmp_a, &tmp_b, 1);
    //     move_count++; // Increment move counter
    //     tmp_a = *stack_a;
    //     tmp_b = *stack_b;

    //     ft_rra(&tmp_a, 1);
    //     move_count++; // Increment move counter

    //     while (tmp_b->nbr < ft_lst_last(tmp_a)->nbr)
    //     {
    //         ft_rra(&tmp_a, 1);
    //         move_count++; // Increment move counter
    //         tmp_a = ft_lst_last(tmp_a); // Update tmp_a after reverse rotation
    //     }
    //     ft_pa(&tmp_a, &tmp_b, 1);
    //     move_count++; // Increment move counter
    // }
    else if (ft_lst_last(tmp_b)->nbr < tmp_a->nbr
        && ft_lst_last(tmp_b)->nbr < ft_lst_last(tmp_a)->nbr
        && ft_lst_last(tmp_b)->nbr > ft_lst_last(tmp_a)->prev->nbr)
    {
        ft_rrr(&tmp_a, &tmp_b, 1);
        move_count++; // Increment move counter
        tmp_a = *stack_a;
        tmp_b = *stack_b;

        ft_pa(&tmp_a, &tmp_b, 1);
        move_count++; // Increment move counter
    }
    else if (ft_lst_last(tmp_b)->nbr < tmp_a->nbr
        && ft_lst_last(tmp_b)->nbr > ft_lst_last(tmp_a)->nbr
        && ft_lst_last(tmp_b)->nbr > ft_lst_last(tmp_a)->prev->nbr)
    {
        ft_rrb(&tmp_b, 1);
        move_count++; // Increment move counter
        tmp_b = *stack_b;

        ft_pa(&tmp_a, &tmp_b, 1);
        move_count++; // Increment move counter
    }

    // Free the deep copies to avoid memory leaks
    ft_free_stack(&tmp_a);
    ft_free_stack(&tmp_b);

	if ((move_count) >= 1)
    	return move_count; // Return the total number of moves
	else
		return (INT_MAX);
}



// int pushb_bot2_tmp(t_stack **stack_a, t_stack **stack_b)
// {
//     int move_count = 0; // Initialize the move counter

//     // Create deep copies of stack_a and stack_b
//     t_stack *tmp_a = deep_copy_stack(*stack_a);
//     t_stack *tmp_b = deep_copy_stack(*stack_b);

//     if (ft_lst_last(tmp_b)->prev->nbr > tmp_a->nbr)
//     {
//         ft_rrb(&tmp_b, 1);
//         move_count++; // Increment move counter
//         ft_rrb(&tmp_b, 1);
//         move_count++; // Increment move counter

//         // Use the deep copy, not the original stack
//         while (tmp_b->nbr > tmp_a->nbr)
//         {
//             ft_ra(&tmp_a, 1);
//             move_count++; // Increment move counter
//         }
//         ft_pa(&tmp_a, &tmp_b, 1);
//         move_count++; // Increment move counter
//     }
//     else if (ft_lst_last(tmp_b)->prev->nbr < tmp_a->nbr
//         && ft_lst_last(tmp_b)->prev->nbr < ft_lst_last(tmp_a)->nbr
//         && ft_lst_last(tmp_b)->prev->nbr > ft_lst_last(tmp_a)->prev->nbr)
//     {
//         ft_rrr(&tmp_a, &tmp_b, 1);
//         move_count++; // Increment move counter
//         ft_rrb(&tmp_b, 1);
//         move_count++; // Increment move counter

//         ft_pa(&tmp_a, &tmp_b, 1);
//         move_count++; // Increment move counter
//     }
//     else if (ft_lst_last(tmp_b)->prev->nbr < tmp_a->nbr
//         && ft_lst_last(tmp_b)->prev->nbr > ft_lst_last(tmp_a)->nbr
//         && ft_lst_last(tmp_b)->prev->nbr > ft_lst_last(tmp_a)->prev->nbr)
//     {
//         ft_rrb(&tmp_b, 1);
//         move_count++; // Increment move counter
//         ft_rrb(&tmp_b, 1);
//         move_count++; // Increment move counter

//         ft_pa(&tmp_a, &tmp_b, 1);
//         move_count++; // Increment move counter
//     }

//     // Free the deep copies to avoid memory leaks
//     ft_free_stack(&tmp_a);
//     ft_free_stack(&tmp_b);

//     if (move_count >= 1)
//         return move_count; // Return the total number of moves
//     else
//         return INT_MAX;
// }


// int pushb_top_tmp(t_stack **stack_a, t_stack **stack_b)
// {
// 	int move_count = 1; // Initialize move counter

// 	// Initialize and assign tmp_a and tmp_b
// 	t_stack *tmp_a = *stack_a;
// 	t_stack *tmp_b = *stack_b;

// 	if (tmp_b->nbr > tmp_a->nbr)
// 	{
// 		while (tmp_b->nbr > tmp_a->nbr)
// 		{
// 			ft_ra(stack_a, 1);
// 			move_count++;
// 			tmp_a = *stack_a; // Update tmp_a after rotation
// 		}
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (tmp_b->nbr < tmp_a->nbr
// 		&& tmp_b->nbr < ft_lst_last(tmp_a)->nbr
// 		&& tmp_b->nbr < ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		while (tmp_b->nbr < ft_lst_last(tmp_a)->nbr)
// 		{
// 			ft_rra(stack_a, 1);
// 			move_count++; // Increment move counter
// 			tmp_a = *stack_a; // Update tmp_a after reverse rotation
// 		}
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (tmp_b->nbr < tmp_a->nbr
// 		&& tmp_b->nbr < ft_lst_last(tmp_a)->nbr
// 		&& tmp_b->nbr > ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rra(stack_a, 1);
// 		move_count++; // Increment move counter
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (tmp_b->nbr < tmp_a->nbr
// 		&& tmp_b->nbr > ft_lst_last(tmp_a)->nbr
// 		&& tmp_b->nbr > ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}

// 	return move_count; // Return the total number of moves
// }



// int pushb_top2_tmp(t_stack **stack_a, t_stack **stack_b)
// {
// 	int move_count = 1; // Initialize the move counter

// 	// Initialize and assign tmp_a and tmp_b
// 	t_stack *tmp_a = *stack_a;
// 	t_stack *tmp_b = *stack_b;

// 	if (tmp_b->next->nbr > tmp_a->nbr)
// 	{
// 		ft_rr(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_a = *stack_a;
// 		tmp_b = *stack_b;

// 		while (tmp_b->nbr > tmp_a->nbr)
// 		{
// 			ft_ra(stack_a, 1);
// 			move_count++;
// 			tmp_a = *stack_a; // Update tmp_a after rotation
// 		}
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (tmp_b->next->nbr < tmp_a->nbr
// 		&& tmp_b->next->nbr < ft_lst_last(tmp_a)->nbr
// 		&& tmp_b->next->nbr < ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_b = *stack_b;

// 		ft_rra(stack_a, 1);
// 		move_count++; // Increment move counter
// 		ft_rra(stack_a, 1);
// 		move_count++; // Increment move counter
// 		tmp_a = *stack_a; // Update tmp_a after reverse rotations

// 		while (tmp_b->nbr < ft_lst_last(tmp_a)->nbr)
// 		{
// 			ft_rra(stack_a, 1);
// 			move_count++; // Increment move counter
// 			tmp_a = *stack_a; // Update tmp_a after reverse rotation
// 		}
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (tmp_b->next->nbr < tmp_a->nbr
// 		&& tmp_b->next->nbr < ft_lst_last(tmp_a)->nbr
// 		&& tmp_b->next->nbr > ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_b = *stack_b;

// 		ft_rra(stack_a, 1);
// 		move_count++; // Increment move counter
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (tmp_b->next->nbr < tmp_a->nbr
// 		&& tmp_b->next->nbr > ft_lst_last(tmp_a)->nbr
// 		&& tmp_b->next->nbr > ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_b = *stack_b;

// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}

// 	return move_count; // Return the total number of moves
// }



// int pushb_bot_tmp(t_stack **stack_a, t_stack **stack_b)
// {
// 	int move_count = 1; // Initialize the move counter

// 	// Initialize and assign tmp_a and tmp_b
// 	t_stack *tmp_a = *stack_a;
// 	t_stack *tmp_b = *stack_b;

// 	if (ft_lst_last(tmp_b)->nbr > tmp_a->nbr)
// 	{
// 		ft_rrb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_b = *stack_b;

// 		while (tmp_b->nbr > tmp_a->nbr)
// 		{
// 			ft_ra(stack_a, 1);
// 			move_count++; // Increment move counter
// 			tmp_a = *stack_a; // Update tmp_a after rotation
// 		}
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (ft_lst_last(tmp_b)->nbr < tmp_a->nbr
// 		&& ft_lst_last(tmp_b)->nbr < ft_lst_last(tmp_a)->nbr
// 		&& ft_lst_last(tmp_b)->nbr < ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rrr(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_a = *stack_a;
// 		tmp_b = *stack_b;

// 		ft_rra(stack_a, 1);
// 		move_count++; // Increment move counter

// 		while (tmp_b->nbr < ft_lst_last(tmp_a)->nbr)
// 		{
// 			ft_rra(stack_a, 1);
// 			move_count++; // Increment move counter
// 			tmp_a = *stack_a; // Update tmp_a after reverse rotation
// 		}
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (ft_lst_last(tmp_b)->nbr < tmp_a->nbr
// 		&& ft_lst_last(tmp_b)->nbr < ft_lst_last(tmp_a)->nbr
// 		&& ft_lst_last(tmp_b)->nbr > ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rrr(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_a = *stack_a;
// 		tmp_b = *stack_b;

// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (ft_lst_last(tmp_b)->nbr < tmp_a->nbr
// 		&& ft_lst_last(tmp_b)->nbr > ft_lst_last(tmp_a)->nbr
// 		&& ft_lst_last(tmp_b)->nbr > ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rrb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_b = *stack_b;

// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}

// 	return move_count; // Return the total number of moves
// }

// int pushb_bot2_tmp(t_stack **stack_a, t_stack **stack_b)
// {
// 	int move_count = 1; // Initialize the move counter

// 	// Initialize and assign tmp_a and tmp_b
// 	t_stack *tmp_a = *stack_a;
// 	t_stack *tmp_b = *stack_b;

// 	if (ft_lst_last(tmp_b)->prev->nbr > tmp_a->nbr)
// 	{
// 		ft_rrb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		ft_rrb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_b = *stack_b;

// 		while (tmp_b->nbr > tmp_a->nbr)
// 		{
// 			ft_ra(stack_a, 1);
// 			move_count++; // Increment move counter
// 			tmp_a = *stack_a; // Update tmp_a after rotation
// 		}
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (ft_lst_last(tmp_b)->prev->nbr < tmp_a->nbr
// 		&& ft_lst_last(tmp_b)->prev->nbr < ft_lst_last(tmp_a)->nbr
// 		&& ft_lst_last(tmp_b)->prev->nbr < ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rrr(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 		ft_rrr(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_a = *stack_a;
// 		tmp_b = *stack_b;

// 		while (tmp_b->nbr < ft_lst_last(tmp_a)->nbr)
// 		{
// 			ft_rra(stack_a, 1);
// 			move_count++; // Increment move counter
// 			tmp_a = *stack_a; // Update tmp_a after reverse rotation
// 		}
// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (ft_lst_last(tmp_b)->prev->nbr < tmp_a->nbr
// 		&& ft_lst_last(tmp_b)->prev->nbr < ft_lst_last(tmp_a)->nbr
// 		&& ft_lst_last(tmp_b)->prev->nbr > ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rrr(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 		ft_rrb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_b = *stack_b;

// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}
// 	else if (ft_lst_last(tmp_b)->prev->nbr < tmp_a->nbr
// 		&& ft_lst_last(tmp_b)->prev->nbr > ft_lst_last(tmp_a)->nbr
// 		&& ft_lst_last(tmp_b)->prev->nbr > ft_lst_last(tmp_a)->prev->nbr)
// 	{
// 		ft_rrb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		ft_rrb(stack_b, 1);
// 		move_count++; // Increment move counter
// 		tmp_b = *stack_b;

// 		ft_pa(stack_a, stack_b, 1);
// 		move_count++; // Increment move counter
// 	}

// 	return move_count; // Return the total number of moves
// }
