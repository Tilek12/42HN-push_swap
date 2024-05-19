/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:16:11 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/18 13:18:19 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------*/
/*  Starts sorting algorithm  */
/*----------------------------*/
void	sorting(t_stack **a, t_stack **b)
{
	int	elements;

	elements = count_elements(*a);
	if (is_sorted(*a) == 1)
		exit_success(a);
	else
	{
		if (elements == 2)
			swap_a(a);
		else if (elements == 3)
			sort_3_elements_in_a(a);
		else if (elements <= 10)
			sort_small_stack(a, b, elements);
		else
			sort_big_stack(a, b, elements);
	}
	if (is_sorted(*a) == 0)
	{
		free_stack(b);
		exit_failure(a);
	}
	else
		free_stack(a);
	free_stack(b);
}
