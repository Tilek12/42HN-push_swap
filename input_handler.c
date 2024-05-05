/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:44:37 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/05 18:39:59 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_in_stack(int nums, char *str_num, t_stack **a)
{
	long	num;
	int		i;

	i = 0;
	while (str_num[i])
	{
		num = ft_atol_error_check(&str_num[i]);
		if ((num == LLONG_MIN) || (repeat_check(*a, (int)num)))
			error_handler(a, str_num);
		add_to_stack(a, (int)num);
		i++;
	}
}

static int	count_numbers(char *s)
{
	int	num_counter;
	int	in_num;

	num_counter = 0;
	in_num = 0;
	while (*s)
	{
		if (*s == ' ')
		{
			if (in_num)
				in_num = 0;
		}
		else
		{
			if (!in_num)
			{
				in_num = 1;
				num_counter++;
			}
		}
		s++;
	}
	return (num_counter);
}

void	input_handler(int argc, char **argv, t_stack **a)
{
	char	**str_num;
	int		nums;

	if (argc == 2)
	{
		str_num = ft_split(argv[1], ' ');
		nums = count_numbers(argv[1]);
		fill_in_stack(nums, *str_num, a);
	}
	else
		fill_in_stack(argc, *argv, a);
}
