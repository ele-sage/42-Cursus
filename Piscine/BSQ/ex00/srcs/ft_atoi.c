/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-sage <ele-sage@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:12:02 by ele-sage          #+#    #+#             */
/*   Updated: 2022/12/14 22:21:24 by ele-sage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_pow(int base, int exp)
{
	unsigned int	result;
	int				i;

	result = 1;
	i = 0;
	while (i++ < exp)
		result *= base;
	return (result);
}

unsigned int	ft_atoi(char *str, int digit_count)
{
	int				i;
	unsigned int	result;

	result = 0;
	i = 0;
	while (i < digit_count)
	{
		result += (str[digit_count - i - 1] - '0') * ft_pow(10, i);
		i++;
	}
	return (result);
}
