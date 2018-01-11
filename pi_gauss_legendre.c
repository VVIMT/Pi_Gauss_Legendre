/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pi_gauss_legendre.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:51:45 by vinvimo           #+#    #+#             */
/*   Updated: 2018/01/09 23:13:58 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

long double		pi_gauss_legendre(long double pi, int precision)
{
	long double	a = 1;
	long double	b = 1 / sqrtl(2);
	long double	t = 1 / (long double)4;
	long double	p = 1;
	long double tmp;

	while (precision > 0)
	{
		tmp = a;
		a = (a + b) / 2;
		b = sqrtl(tmp * b);
		t = t - (p * powl(tmp - a, 2));
		p = 2 * p;
		precision--;
	}
	pi = (powl(a + b, 2)) / (4 * t);
	return (pi);
}
