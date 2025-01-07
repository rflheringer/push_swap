/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:22:52 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/07 16:45:55 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main (int argc, char **argv)
{
	t_push	*push_swap;

	if (argc == 2)
	{
		push_swap = init_push_swap(argc, argv);
		validate_args(push_swap);
		init_stacks(push_swap);
		if (!check_ordered(push_swap->stack_a))
		{
			if (push_swap->length_a <= 10)
				small_sort(push_swap);
			else
				big_sort(push_swap);
		}
		free_and_close(push_swap, EXIT_SUCCESS);
	}
	else	
		message_error(EXIT_NO_ARGS);
	return (0);
}
