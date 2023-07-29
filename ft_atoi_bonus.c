/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surkim <surkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:36:30 by surkim            #+#    #+#             */
/*   Updated: 2023/07/29 16:27:02 by surkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	is_white(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ans;
	int	flag;

	i = -1;
	flag = 1;
	ans = 0;
	while (str[++i])
		if (is_white(str[i]) == 0)
			break ;
	if (str[i] == '-')
	{
		flag = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (flag * ans);
		ans = ans * 10 + str[i] - '0';
		i++;
	}
	return (flag * ans);
}

int	ft_ctoi(char x)
{
	if (x >= '0' && x <= '9')
		return (x - '0');
	else if (x >= 'A' && x <= 'F')
		return (x - 'A' + 10);
	else
		return (x - 'a' + 10);
}

int	ft_axtoi(char *str)
{
	int	i;
	int	len;
	int	tmp;
	int	ans;

	if (str == 0)
		return (0xffffff);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	len--;
	i = 2;
	ans = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp = ft_ctoi(str[i]);
		ans += (tmp * (int)pow(16, len - i));
		i++;
	}
	return (ans);
}
