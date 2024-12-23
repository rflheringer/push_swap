/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheringe <rheringe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:02:48 by rheringe          #+#    #+#             */
/*   Updated: 2024/12/23 18:40:21 by rheringe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	validate_args(t_push *push_swap)
{
	size_t	index;
	long	nbr;

	if (!check_duplication(push_swap->argv) || *push_swap->argv == NULL)
		free_and_close(push_swap, EXIT_FAILURE);
	
	index = 0;
	nbr = 0;
	while (push_swap->argv[index])
	{
		if(!check_letters(push_swap->argv[index]))
			free_and_close(push_swap, EXIT_FAILURE);
		nbr = ft_atoi(push_swap->argv[index]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_and_close(push_swap, EXIT_FAILURE); 
		index++;
	}
}
t_bool	check_duplication(char *argv_split_list[])
{
	 size_t	index;
	 size_t	index2;
	 long	nbr;

	 index = 0;
	 while (argv_split_list[index])
	 {
		nbr = ft_atoi(argv_split_list[index]);
		index2 = index + 1;
		while(argv_split_list[index2])
		{
			if (nbr == ft_atoi(argv_split_list[index2]))
				return (FALSE);
			index2++;
		}
		index++;
	 }
	 return (TRUE);
}
t_bool check_letters(char *nbr)
{
	
}
