/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:52:58 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/15 15:13:03 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	// first calulate Varycentric coordinates
	Fixed	denominator = (b.getY() - c.getY()) * (a.getX() - c.getX()) + 
							(c.getX() - b.getX()) * (a.getY() - c.getY());
	Fixed	alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + 
						(c.getX() - b.getX()) * (point.getY() - c.getY())) / denominator;
	Fixed	beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + 
						(a.getX() - c.getX()) * (point.getY() - c.getY())) / denominator;
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
