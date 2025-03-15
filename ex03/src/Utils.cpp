/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:52:58 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/15 15:53:04 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// A(x1, y1), B(x2, y2), C(x3, y3), -> P(x, y) searching for this one 
	// Fixed x1 = a.getX(); but like that i create more objs
	const Fixed &x1 = a.getX(); // now x1 is a reference—no copy made!
	const Fixed &y1 = a.getY(); 
	const Fixed &x2 = b.getX(); 
	const Fixed &y2 = b.getY(); 
	const Fixed &x3 = c.getX(); 
	const Fixed &y3 = c.getY(); 
	const Fixed &x = point.getX(); 
	const Fixed &y = point.getY(); 

	// first calulate Varycentric coordinates
	Fixed	denominator = (y2- y3) * (x1 - x3) + 
							(x3 - x2) * (y1 - y3);
	Fixed	alpha = ((y2- y3) * (x - x3) + 
						(x3 - x2) * (y - y3)) / denominator;
	Fixed	beta = ((y3 - y1) * (x - x3) + 
						(x1 - x3) * (y - y3)) / denominator;
	Fixed	gamma = Fixed(1.0f) - alpha - beta; // ? wants 1.0f
 
	return (alpha >= Fixed(0.0f) && alpha <= Fixed(1.0f)) && (beta >= Fixed(0.0f) && beta <= Fixed(1.0f))	
			&& (gamma >= Fixed(0.0f) && gamma <= Fixed(1.0f));
}

// * more clever return would be
// return (alpha > Fixed(0) && beta > Fixed(0) && gamma > Fixed(0));
// Example (why only > 0 is enough):
// If: α = 0.8, β = 0.5, γ would have to be -0.3 (to keep sum = 1). Negative γ means outside the triangle.
// If: α = 1.2, this implies one of β or γ would need to be negative, thus again outside triangle.
// Hence, simply checking if each barycentric coordinate is positive automatically ensures they're also ≤ 1 (given that α+β+γ=1).
