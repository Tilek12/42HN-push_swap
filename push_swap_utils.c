/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:29:53 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/08 11:16:49 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	long	is_whitespace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static	long	check_int_overflow(long number)
{
	if ((number > INT_MAX) || (number < INT_MIN))
		return (LONG_MAX);
	else
		return (number);
}

// Changes strint to long
long	ft_atol(char *str)
{
	int		i;
	long	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = sign * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0') && (str[i] <= '9'))
			result = (result * 10) + (str[i] - '0');
		else
			return (LONG_MAX);
		i++;
	}
	return (check_int_overflow(result * sign));
}

// Counts how many numbers are in the string
int	count_numbers(char **str_num)
{
	int counter;
	int i;

	counter = 0;
	i = 0;
	while (str_num[i] != NULL)
	{
		counter++;
		i++;
	}
	return counter;
}

// Deallocates all used memory
void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
