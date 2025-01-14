/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:05:17 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/14 15:43:35 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../includes/get_next_line.h"

void	read_commands(t_push *push_swap)
{
	size_t	counter;
	char	*command;

	counter = 1;
	if (ft_isatty(STDIN_FILENO))
		ft_printf("\033[37;4mEnter a command (Ctrl+D to stop):\033[0m\n");
	while (TRUE)
	{
		if (ft_isatty(STDIN_FILENO))
			ft_printf("\033[34;3m%dst command\033[0m\033[37;3m>\033[0m ",
				counter++);
		command = get_next_line(STDIN_FILENO);
		if (command == NULL)
			break ;
		execute_commands(push_swap, command);
		free(command);
	}
}

void	execute_commands(t_push *push_swap, char *command)
{
	if (!ft_strncmp(command, "sa\n", 3))
		swap(push_swap, sa, FALSE);
	else if (!ft_strncmp(command, "sb\n", 3))
		swap(push_swap, sb, FALSE);
	else if (!ft_strncmp(command, "ss\n", 3))
		swap(push_swap, ss, FALSE);
	else if (!ft_strncmp(command, "pa\n", 3))
		push(push_swap, pa, FALSE);
	else if (!ft_strncmp(command, "pb\n", 3))
		push(push_swap, pb, FALSE);
	else if (!ft_strncmp(command, "ra\n", 3))
		rotate(push_swap, ra, FALSE);
	else if (!ft_strncmp(command, "rb\n", 3))
		rotate(push_swap, rb, FALSE);
	else if (!ft_strncmp(command, "rr\n", 3))
		rotate(push_swap, rr, FALSE);
	else if (!ft_strncmp(command, "rra\n", 4))
		reverse_rotate(push_swap, rra, FALSE);
	else if (!ft_strncmp(command, "rrb\n", 4))
		reverse_rotate(push_swap, rrb, FALSE);
	else if (!ft_strncmp(command, "rrr\n", 4))
		reverse_rotate(push_swap, rrr, FALSE);
	else
		clear_invalid_movment(push_swap, command);
}

void	verify_stack(t_push *push_swap)
{
	size_t	length;

	length = stack_length(push_swap->stack_a);
	if ((check_ordered(push_swap->stack_a)) && \
		(length == push_swap->length_a) && \
		(push_swap->stack_b == NULL))
		ft_printf("\n\033[32;1mOK\033[0m\n");
	else
		ft_printf("\n\033[31;1mKO\033[0m\n");
}
