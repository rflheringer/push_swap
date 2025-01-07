/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:13:50 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/07 12:48:44 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_push *push_swap)
{
	t_stack	*smallest_node;
	int		smallest_pos;

	move_all_to_b(push_swap);
	if (!check_ordered(push->stack_a))
		sort_three(push_swap);
	while (push_swap->stack_b != NULL)
	{
		set_position(push_swap->stack_a);
		set_position(push_swap->stack_b);
		set_match_node(push_swap->stack_a, push_swap->stack_b);
		set_cost(push_swap->stack_a, push_swap->stack_b);
		lcost_top(push_swap);
		push(push_swap, pa, TRUE);
	}
	set_position(push_swap->stack_a);
	smallest_pos = find_smalles_position(push_swap->stack_a);
	smallest_node = get_node(push_swap->stack_a, smallest_pos);
	while (push_swap->stack_a != smallest_node)
	{
		finalize_sorting(push_swap, smallest_node, a);
	}
}