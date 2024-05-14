/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:52:48 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/14 18:00:09 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-----------------------------------------------------------*/
/*  Checks if the element is closer to the top of the stack  */
/*-----------------------------------------------------------*/
int	is_element_closer_to_top(int index, int elements)
{
	if (index <= (elements / 2))
		return (1);
	else
		return (0);
}

/*--------------------------------------------------------*/
/*  Finds the index of the smallest element in the stack  */
/*--------------------------------------------------------*/
int	find_index_of_smallest(t_stack *stack)
{
	t_stack	*temp;
	int		min_value;
	int		min_index;

	temp = stack;
	min_value = INT_MAX;
	min_index = 0;
	while (temp)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
			min_index = temp->index;
		}
		temp = temp->next;
	}
	return (min_index);
}

/*--------------------------------------------------------*/
/*  Finds the value of the smallest element in the stack  */
/*--------------------------------------------------------*/
int	find_value_of_smallest(t_stack *stack)
{
	t_stack	*temp;
	int		min_value;

	temp = stack;
	min_value = INT_MAX;
	while (temp)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
		}
		temp = temp->next;
	}
	return (min_value);
}

/*---------------------------------------------------------------------*/
/*  A modified version of Selection Sort:                              */
/*  1. Finds the smallest number in stack a and brings it to the top.  */
/*  2. Pushes it to stack b.                                           */
/*  3. Repeats steps 1-2 until 3 elements stay in stack a.             */
/*  4. Sorts 3 elements in stack a.                                    */
/*  5. Pushes all elements from stack b back to stack a.               */
/*---------------------------------------------------------------------*/
/*  Sorts only small stacks. Useless for big stacks  */
/*---------------------------------------------------*/
void	sort_small_stack(t_stack **a, t_stack **b, int elements)
{
	int	min_value;
	int	min_index;

	while (elements > 3)
	{
		min_value = find_value_of_smallest(*a);
		min_index = find_index_of_smallest(*a);
		while ((*a)->value != min_value)
		{
			if (is_element_closer_to_top(min_index, elements) == 1)
				rotate_a(a);
			else
				rev_rotate_a(a);
		}
		push_b(b, a);
		elements--;
	}
	sort_3_elements_in_a(a);
	while (count_elements(*b) > 0)
		push_a(a, b);
}
