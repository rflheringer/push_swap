/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 13:53:35 by rheringe          #+#    #+#             */
/*   Updated: 2024/12/23 14:55:11 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push init_push_swap(int argc, char **argv)
{
	t_push	*push_swap;
	push_swap = (t_push *)malloc(sizeof(t_push));
	if(!push_swap)
		message_error(EXIT_FAILURE);
	push_swap->stack_a = NULL;
	push_swap->stack_b = NULL;
	push_swap->length_a = 0;
	push_swap->length_b = 0;
	push_swap->argv_checker = FALSE;
	if (argc == 2)
	{
		push_swap->argv = (ft_split(argv[1], ' '));
		push_swap->argv_checker = TRUE;
	}
	else
		push_swap->argv = ++argv;
	return (push_swap);
}

