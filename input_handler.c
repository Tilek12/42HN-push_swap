/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:44:37 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/13 12:04:13 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*--------------------------------------------*/
/*  Checks for repeating number in the stack  */
/*--------------------------------------------*/
int	repeat_check(t_stack *stack, int num)
{
	t_stack	*tmp_node;

	tmp_node = stack;
	while (tmp_node != NULL)
	{
		if (tmp_node->value == num)
			return (1);
		tmp_node = tmp_node->next;
	}
	return (0);
}

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
	new_node->value = num;
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
		if ((num == LONG_MAX) || (repeat_check(*stack, (int)num) == 1))
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
		str_num = ft_split(argv[1], ' ');
		if (!str_num)
			exit_failure(stack);
		nums = count_numbers(str_num);
		if (nums == 1)
			exit_success(stack);
		fill_in_stack(nums, str_num, stack);
		free_str(str_num);
	}
	else
		fill_in_stack((argc - 1), (argv + 1), stack);
}
