/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:22:52 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/06 14:52:46 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_list	push_swap;

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
		clear_all(push_swap, EXIT_SUCCESS);
	}
	else	
		message_error(EXIT_NO_ARGS);
	return (0);
}




























// char **handle_string(char **argv)
// {
// 	if (*argv[1] == '\0')
// 		printf ("ERRO");
// 	argv = ft_split(argv[1], ' ');
// 	while (*argv){
// 		printf ("%s\n" ,*argv);
// 		argv++;
// 	}
// 	return (argv);
// }


// int main (int argc, char **argv)
// {
// 	if (argc > 2)
// 	{
// 		handle_string(argv);		
// 	}
// 	return (0);
// }
