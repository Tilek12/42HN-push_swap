/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:09:56 by tkubanyc          #+#    #+#             */
/*   Updated: 2024/05/05 18:14:15 by tkubanyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft_own/libft.h"
# include "libft_own/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	input_handler(int argc, char **argv, t_stack **a);
int		ft_atol_error_check(const char *str);
void	error_handler(t_stack a, char *str_num);

#endif
