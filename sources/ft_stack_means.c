/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_means.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 20:04:47 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/28 19:46:27 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Calculate mean1 for elements <= mean
int ft_mean4_stack(t_stack **stack_a) {
	int mean4 = 0;
	int sum = 0;
	int count = 0;
	int mean = ft_stack_mean(stack_a);
	t_stack *temp = *stack_a;

	while (temp) {
		if (temp->nbr <= mean) {
			sum += temp->nbr;
			count++;
		}
		temp = temp->next;
	}

	if (count > 0)
		mean4 = sum / count; // Only divide if count is greater than 0
	else
		mean4 = 0; // Handle the case where no elements satisfy the condition

	return mean4;
}

// Calculate mean3 for elements > mean
int ft_mean12_stack(t_stack **stack_a) {
	int mean12 = 0;
	int sum = 0;
	int count = 0;
	int mean = ft_stack_mean(stack_a);
	t_stack *temp = *stack_a;

	while (temp) {
		if (temp->nbr > mean) {
			sum += temp->nbr;
			count++;
		}
		temp = temp->next;
	}

	if (count > 0)
		mean12 = sum / count; // Only divide if count is greater than 0
	else
		mean12 = 0; // Handle the case where no elements satisfy the condition

	return mean12;
}

int ft_mean2_stack(t_stack **stack_a) {
	int mean2 = 0;
	int sum = 0;
	int count = 0;
	int mean4 = ft_mean4_stack(stack_a);
	t_stack *temp = *stack_a;

	while (temp) {
		if (temp->nbr <= mean4) {
			sum += temp->nbr;
			count++;
		}
		temp = temp->next;
	}

	if (count > 0)
		mean2 = sum / count; // Only divide if count is greater than 0
	else
		mean2 = 0; // Handle the case where no elements satisfy the condition

	return mean2;
}

int ft_mean6_stack(t_stack **stack_a) {
    int mean6 = 0;
    int sum = 0;
    int count = 0;
    int mean4 = ft_mean4_stack(stack_a);
    int stack_mean = ft_stack_mean(stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > mean4 && temp->nbr <= stack_mean) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean6 = sum / count; // Only divide if count is greater than 0
    else
        mean6 = 0; // Handle the case where no elements satisfy the condition

    return mean6;
}

int ft_mean10_stack(t_stack **stack_a) {
    int mean10 = 0;
    int sum = 0;
    int count = 0;
    int stack_mean = ft_stack_mean(stack_a);
    int mean12 = ft_mean12_stack(stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > stack_mean && temp->nbr <= mean12) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean10 = sum / count; // Only divide if count is greater than 0
    else
        mean10 = 0; // Handle the case where no elements satisfy the condition

    return mean10;
}

int ft_mean14_stack(t_stack **stack_a) {
    int mean14 = 0;
    int sum = 0;
    int count = 0;
    int mean12 = ft_mean12_stack(stack_a);
    int stack_max = ft_max(*stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > mean12 && temp->nbr <= stack_max) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean14 = sum / count; // Only divide if count is greater than 0
    else
        mean14 = 0; // Handle the case where no elements satisfy the condition

    return mean14;
}

int ft_mean1_stack(t_stack **stack_a) {
    int mean1 = 0;
    int sum = 0;
    int count = 0;
    int stack_min = ft_min(*stack_a);
    int mean2 = ft_mean2_stack(stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr >= stack_min && temp->nbr <= mean2) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean1 = sum / count; // Only divide if count is greater than 0
    else
        mean1 = 0; // Handle the case where no elements satisfy the condition

    return mean1;
}

int ft_mean3_stack(t_stack **stack_a) {
    int mean3 = 0;
    int sum = 0;
    int count = 0;
    int mean2 = ft_mean2_stack(stack_a);
    int mean4 = ft_mean4_stack(stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > mean2 && temp->nbr <= mean4) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean3 = sum / count;
    else
        mean3 = 0;

    return mean3;
}

int ft_mean5_stack(t_stack **stack_a) {
    int mean5 = 0;
    int sum = 0;
    int count = 0;
    int mean4 = ft_mean4_stack(stack_a);
    int mean6 = ft_mean6_stack(stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > mean4 && temp->nbr <= mean6) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean5 = sum / count;
    else
        mean5 = 0;

    return mean5;
}

int ft_mean7_stack(t_stack **stack_a) {
    int mean7 = 0;
    int sum = 0;
    int count = 0;
    int mean6 = ft_mean6_stack(stack_a);
    int stack_mean = ft_stack_mean(stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > mean6 && temp->nbr <= stack_mean) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean7 = sum / count;
    else
        mean7 = 0;

    return mean7;
}


int ft_mean9_stack(t_stack **stack_a) {
    int mean9 = 0;
    int sum = 0;
    int count = 0;
    int stack_mean = ft_stack_mean(stack_a);
    int mean10 = ft_mean10_stack(stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > stack_mean && temp->nbr <= mean10) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean9 = sum / count;
    else
        mean9 = 0;

    return mean9;
}

int ft_mean11_stack(t_stack **stack_a) {
    int mean11 = 0;
    int sum = 0;
    int count = 0;
    int mean10 = ft_mean10_stack(stack_a);
    int mean12 = ft_mean12_stack(stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > mean10 && temp->nbr <= mean12) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean11 = sum / count;
    else
        mean11 = 0;

    return mean11;
}

int ft_mean13_stack(t_stack **stack_a) {
    int mean13 = 0;
    int sum = 0;
    int count = 0;
    int mean12 = ft_mean12_stack(stack_a);
    int mean14 = ft_mean14_stack(stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > mean12 && temp->nbr <= mean14) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean13 = sum / count;
    else
        mean13 = 0;

    return mean13;
}

int ft_mean15_stack(t_stack **stack_a) {
    int mean15 = 0;
    int sum = 0;
    int count = 0;
    int mean14 = ft_mean14_stack(stack_a);
    int max = ft_max(*stack_a);
    t_stack *temp = *stack_a;

    while (temp) {
        if (temp->nbr > mean14 && temp->nbr <= max) {
            sum += temp->nbr;
            count++;
        }
        temp = temp->next;
    }

    if (count > 0)
        mean15 = sum / count;
    else
        mean15 = 0;

    return mean15;
}


