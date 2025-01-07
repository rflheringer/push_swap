/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:24:10 by rheringe          #+#    #+#             */
/*   Updated: 2025/01/07 12:29:08 by rheringe         ###   ########.fr       */
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

typedef enum e_bool
{
	FALSE,
	TRUE
}t_bool;


//libs


//handle_errors functions
void	free_stack(t_stack stack);
void	message_error(short error_code);
void	free_split_list(char **split_list);
void	free_and_close(t_push *push_swap, short exit_code);

//init_push_swap functions
int		init_push_swap(argc, argv);
void	init_stacks(t_push *push_swap);
void	link_node(t_stack **stack, int value);

//validate_arguments functions
void	validate_args(t_push **push_swap);
t_bool	check_letters(char *nbr);
t_bool	check_duplication(char *argv_split_list[]);

//handle_nodes functions
t_stack	*create_node(int value);

//handle_stacks functions
size_t stack_length(t_stack *stack);

//handle_sort functions
void	set_position(t_stack *stack);
t_bool	check_ordered(t_stack *stack);
int	find_first_pos(t_stack *stack);
int	find_last_pos(t_stack *stack);

//small_sort functions
void	small_sort(t_push *push_swap);
void	sort_three (t_push *push_swap);
void	*sort_few_elements(t_push *push_swap);

//movments functions
void	swap(t_push *push_swap, t_mv type, t_bool print_mv);
void	execute_swap(t_stack **stack);
void	rotate(t_push *push_swap, t_mv type, t_bool print_mv);
void	execute_rotate(t_stack **t_stack);
void	push(t_push *push_swap, t_mv type, t_bool print_mv);
void	execute_push(t_stack **dst_stack, t_stack **src_stack);
void	reverse_rotate(t_push *push_swap, t_mv type, t_bool print_mv);
void	execute_rev_rot(t_stack **stack);

#endif

