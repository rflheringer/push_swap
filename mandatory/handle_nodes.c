/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:38:59 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/06 12:50:17 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		handle_errors(EXIT_FAILURE);
	new_node->value = value;
	new_node->position = 0;
	new_node->local = 0;
	new_node->above_center = FALSE;
	new_node->lower = FALSE;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->match_node = NULL;
	return (new_node);
}

t_stack	*find_last_node(t_stack *stack)
{
	if (stack == NULL)
		handle_errors(EXIT_FAILURE);
	while(stack->next != NULL)
		stack = stack->next;
	return (stack);	
}

