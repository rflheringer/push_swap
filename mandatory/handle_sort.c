/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:06:10 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/07 12:33:39 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack *stack)
{
	int	current_position;
	int	center_line;

	if (stack == NULL)
		return (0);
	current_position = 0;
	center_line = stack_length(stack) / 2;
	while (stack != NULL)
	{
		stack->position = current_position;
		if (current_position <= center_line)
			stack->above_center = TRUE;
		else if (current_position > center_line)
			stack->above_center = FALSE;
		stack = stack->next;
		++current_position;
	}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
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

int	find_first_pos(t_stack *stack)
{
	int	pos;
	int	temp_min;

	pos = 0;
	temp_min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < temp_min)
		{
			temp_min = stack->value;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}

int	find_last_pos(t_stack *stack)
{
	int	pos;
	int	temp_max;

	position = 0;
	temp_max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > temp_max)
		{
			temp_max = stack->value;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}