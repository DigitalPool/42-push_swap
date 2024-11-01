/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_new_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 16:44:19 by ashobajo          #+#    #+#             */
/*   Updated: 2024/08/23 21:40:43 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *ft_create_new_node(int value)
{
	t_stack *new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		ft_print_error();
	new_node->nbr = value;
	new_node->pos = 0;
	new_node->next = NULL;
	new_node->prev = NULL;

	return (new_node);
}
