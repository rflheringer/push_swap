/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:24:10 by rheringe          #+#    #+#             */
/*   Updated: 2024/12/23 16:46:50 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define EXIT_NO_ARGS -1
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1



typedef struct s_list 
{
	int 	num;	
	struct	s_list *next;
}t_list;

typedef struct s_push
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_bool		check_argv;
	char		**argv;
	size_t		length_a;
	size_t		length_b;
}t_push;


//handle_errors functions
void	message_error(short error_code);
void	free_and_close(t_push *push_swap, short exit_code);
void	free_split_list(char **split_list);
void	free_stack(t_stack stack);

//init_push_swap functions
int		init_push_swap(argc, argv);

//validate_arguments functions
void	validate_args(t_push **push_swap);

#endif

