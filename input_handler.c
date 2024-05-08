/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:44:37 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/08 11:23:04 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Adds number into the stack a
static void	add_to_stack(t_stack **a, int num)
{
	t_stack		*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		error_handler(a);
	if (*a == NULL)
		new_node->index = 0;
	else
		new_node->index = (*a)->index + 1;
	new_node->value = num;
	new_node->prev = *a;
	new_node->next = NULL;
	if (*a)
		(*a)->next = new_node;
	*a = new_node;
	ft_printf("The [%d] value in stack a is: %d\n", new_node->index, new_node->value);
}

// Fills in the stack a with numbers
static void	fill_in_stack(int nums, char **str_num, t_stack **a)
{
	long	num;
	int		i;

	i = 0;
	while (i < nums)
	{
		num = ft_atol(str_num[i]);
		if ((num == LONG_MAX) || (repeat_check(*a, (int)num) == 1))
			error_handler(a);
		add_to_stack(a, (int)num);
		i++;
	}
}

// Gets all arguments as numbers and puts them into stack a
void	input_handler(int argc, char **argv, t_stack **a)
{
	char	**str_num;
	int		nums;
	int		i = 0;

	ft_printf("argc = %d\n", argc);
	while (argv[i])
	{
		ft_printf("argv[%d] = %s\n", i, argv[i]);
		i++;
	}
	if (argc == 2)
	{
		str_num = ft_split(argv[1], ' ');
		i = 0;
		while (str_num[i])
		{
			ft_printf("str_num[%d] = %s\n", i, str_num[i]);
			i++;
		}
		if(!str_num)
			error_handler(a);
		nums = count_numbers(str_num);
		ft_printf("nums = %d\n", nums);
		fill_in_stack(nums, str_num, a);
		free_str(str_num);
	}
	else
		fill_in_stack(argc - 1, (argv + 1), a);
}
