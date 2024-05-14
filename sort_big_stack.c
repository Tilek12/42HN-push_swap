/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:54:29 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/14 18:03:45 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-------------------------------------------------------*/
/*  Finds the index of the biggest element in the stack  */
/*-------------------------------------------------------*/
int	find_index_of_biggest(t_stack *stack)
{
	t_stack	*temp;
	int		max_value;
	int		max_index;

	temp = stack;
	max_value = INT_MIN;
	max_index = 0;
	while (temp)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
			max_index = temp->index;
		}
		temp = temp->next;
	}
	return (max_index);
}

/*-------------------------------------------------------*/
/*  Finds the value of the biggest element in the stack  */
/*-------------------------------------------------------*/
int	find_value_of_biggest(t_stack *stack)
{
	t_stack	*temp;
	int		max_value;

	temp = stack;
	max_value = INT_MIN;
	while (temp)
	{
		if (temp->value > max_value)
		{
			max_value = temp->value;
		}
		temp = temp->next;
	}
	return (max_value);
}

/*----------------------------------------------*/
/*  Chooses the element with the biggest value  */
/*  and pushes it from stack b to stack a.      */
/*----------------------------------------------*/
void	move_to_a(t_stack **a, t_stack **b)
{
	int		max_value;
	int		max_index;

	while (count_elements(*b) > 0)
	{
		max_index = find_index_of_biggest(*b);
		max_value = find_value_of_biggest(*b);
		while ((*b)->value != max_value)
		{
			if (is_element_closer_to_top(max_index, count_elements(*b)) == 1)
				rotate_b(b);
			else
				rev_rotate_b(b);
		}
		push_a(a, b);
	}
}

/*----------------------------------------------------------*/
/*  Moves all elements from stack a to stack b in K-Order   */
/*----------------------------------------------------------*/
/*  1. If the top of stack a is the smallest number,        */
/*     then pushes it to stack b and rotates b              */
/*  2. If the top of stack a is a number in a range closer  */
/*     to the smallest, then pushes it to stack b           */
/*  3. Otherwise, rotates stack a.                          */
/*  4. Repeats steps 1-3 until stack a is empty.            */
/*  5. Pushes all elements from stack b back to stack a.    */
/*----------------------------------------------------------*/
void	move_to_b(t_stack **a, t_stack **b, int elements)
{
	int	range;
	int	min_value;

	range = ft_sqrt(elements) * 1.4;
	while (count_elements(*a) > 0)
	{
		min_value = find_value_of_smallest(*a);
		if ((*a)->value == min_value)
		{
			push_b(b, a);
			rotate_b(b);
		}
		else if ((*a)->value <= (min_value + range))
		{
			push_b(b, a);
		}
		else
			rotate_a(a);
	}
}

/*-------------------------------------------*/
/*  Starts K-Sorting. Useful for big stacks  */
/*-------------------------------------------*/
void	sort_big_stack(t_stack **a, t_stack **b, int elements)
{
	move_to_b(a, b, elements);
	move_to_a(a, b);
}
