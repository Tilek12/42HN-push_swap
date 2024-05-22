/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:53:15 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/22 15:50:22 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*-----------------------------------------------*/
/*  Checks if the only spaces are in the string  */
/*-----------------------------------------------*/
int	is_spaces_only(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != 2 && str[i] != 3)
			return (0);
		i++;
	}
	return (1);
}

/*------------------------------------*/
/*  Checks if the string is a number  */
/*------------------------------------*/
int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-')
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*------------------------------------------------*/
/*  Checks if the string consist of numbers only  */
/*------------------------------------------------*/
int	if_all_numbers(char **str_num)
{
	int	i;

	i = 0;
	while (str_num[i])
	{
		if (!is_number(str_num[i]))
			return (0);
		i++;
	}
	return (1);
}

/*----------------------------------------------------------*/
/*  Checks if there are any repeated numbers in the string  */
/*----------------------------------------------------------*/
int	is_repeated(char **str_num)
{
	int	i;
	int	j;

	i = 0;
	while (str_num[i])
	{
		j = i + 1;
		while (str_num[j])
		{
			if (ft_strncmp(str_num[i], str_num[j],
					ft_strlen(str_num[j]) + 1) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*-----------------------------------------------*/
/*  Checks if the string includes only integers  */
/*-----------------------------------------------*/
int	is_int(char **str)
{
	long	num;
	int		i;

	i = 0;
	while (str[i])
	{
		num = ft_atol(str[i]);
		if (num == LONG_MAX)
			return (0);
		i++;
	}
	return (1);
}
