/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:54:59 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/07 17:04:09 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t stack_length(t_stack *stack)
{
	size_t	length;

	if (stack == NULL)
		return (0);
	length = 1;
	while (stack->next != NULL)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

t_bool	check_ordered(t_stack *stack)
{
	t_stack	*temp;

	if (stack == NULL)
		return (FALSE);
	temp = stack;
	while (temp->stack)
	{
		if (temp->value > temp->next->value)
			return (FALSE);
		temp = temp->next;
	}
	return (TRUE);
}
void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	
	if (stack != NULL)
	{
		while (*stack)
		{
			temp = *stack;
			*stack = (*stack)->next;
			free(temp);
		}
		*stack = NULL;                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	}
}
int	get_match_node_price(t_stack *stack, size_t len_match_stack)
{
	int	cost;

	cost = 0;
	if (stack->match_node->above_center)
		cost += stack->match_node->pos;
	else
		cost += (len_match_stack - stack->match_node->pos);
	return (cost);
}
