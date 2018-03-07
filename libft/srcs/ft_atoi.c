/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 18:04:18 by tgreil            #+#    #+#             */
/*   Updated: 2018/02/06 18:13:06 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_neg_limit(char *str)
{
	if (str[0] == '-' && str[1] == '2' && str[2] == '1' && str[3] == '4' &&
		str[4] == '7' && str[5] == '4' && str[6] == '8' && str[7] == '3' &&
		str[8] == '6' && str[9] == '4' && str[10] == '8')
		return (1);
	return (0);
}

int			ft_atoi(char *str)
{
	int nbr;
	int is_neg;

	is_neg = 1;
	nbr = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\r' || *str == '\f')
		str++;
	if (is_neg_limit(str))
		return (-2147483648);
	if (*str == '-')
	{
		is_neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (is_neg * nbr);
		nbr = nbr * 10 + *str - '0';
		str++;
	}
	return (is_neg * nbr);
}
