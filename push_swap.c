/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:09:10 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/09 19:56:07 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp_a;
	t_stack	*temp_b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	input_handler(argc, argv, &a);
	temp_a = a;
	while (temp_a)
	{
		ft_printf("The [%d] number in stack a is: %d\n", temp_a->index, temp_a->value);
		temp_a = temp_a->next;
	}
	push_b(&b, &a);
	temp_a = a;
	while (temp_a)
	{
		ft_printf("The [%d] number in stack a is: %d\n", temp_a->index, temp_a->value);
		temp_a = temp_a->next;
	}
	temp_b = b;
	while (temp_b)
	{
		ft_printf("The [%d] number in stack b is: %d\n", temp_b->index, temp_b->value);
		temp_b = temp_b->next;
	}
	return (0);
}
