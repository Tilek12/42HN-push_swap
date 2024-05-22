/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:44:37 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/22 15:38:39 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------*/
/*  Adds new number into the stack  */
/*----------------------------------*/
static void	add_to_stack(t_stack **stack, int num)
{
	t_stack	*temp;
	t_stack	*new_node;

	temp = *stack;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit_failure(stack);
	new_node->real_value = num;
	new_node->value = 0;
	if (temp != NULL)
	{
		new_node->index = temp->index + 1;
		temp->next = new_node;
	}
	else
	{
		new_node->index = 0;
		*stack = new_node;
	}
	new_node->next = NULL;
}

/*-----------------------------------*/
/*  Fills in the stack with numbers  */
/*-----------------------------------*/
static void	fill_in_stack(int nums, char **str_num, t_stack **stack)
{
	long	num;
	int		i;

	i = 0;
	while (i < nums)
	{
		num = ft_atol(str_num[i]);
		if (num == LONG_MAX)
			exit_failure(stack);
		add_to_stack(stack, (int)num);
		i++;
	}
}

/*------------------------------------------------------------*/
/*  Gets all arguments as numbers and puts them into stack a  */
/*------------------------------------------------------------*/
void	input_handler(int argc, char **argv, t_stack **stack)
{
	char	**str_num;
	int		nums;

	if (argc == 2)
	{
		if ((argv[1][0] == '\0') || is_spaces_only(argv[1]))
			exit_failure(stack);
		str_num = ft_split(argv[1], ' ');
		if (!str_num || !if_all_numbers(str_num)
			|| is_repeated(str_num) || !is_int(str_num))
		{
			free_str(str_num);
			exit_failure(stack);
		}
		nums = count_numbers(str_num);
		fill_in_stack(nums, str_num, stack);
		free_str(str_num);
	}
	else
	{
		if (!if_all_numbers(argv + 1) || is_repeated(argv + 1))
			exit_failure(stack);
		fill_in_stack((argc - 1), (argv + 1), stack);
	}
	update_stack_values(stack, count_elements(*stack));
}
