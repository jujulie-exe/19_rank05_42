/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfranco <jfranco@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:30:58 by jfranco           #+#    #+#             */
/*   Updated: 2025/07/21 17:45:07 by jfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
T max(T x, T y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

template <typename T>
T min(T x, T y)
{
	if (x <= y)
		return (x);
	else
		return (y);
}

template <typename T>
void swap(T& x, T& y)
{
	T temp = y;
	y = x;
	x = temp;
}

#endif
