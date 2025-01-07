/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:54:59 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/06 12:55:00 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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