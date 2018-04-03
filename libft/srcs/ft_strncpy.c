/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgreil <tgreil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:16:23 by tgreil            #+#    #+#             */
/*   Updated: 2018/04/03 12:38:14 by tgreil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (*src && i < n)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}
