/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:52:52 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/15 13:00:44 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include "../include/Point.hpp"


Point::Point() : x(0), y(0) {}																		// * Constructor

Point::Point(const float xValue, const float yValue) : x(Fixed(xValue)), y(Fixed(yValue)) {}		// * Constructor with parameters

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}											// * Copy constructor

Point &Point::operator= (const Point &copy)															// * Copy assignment
{
	// if (this != copy) // ! it is wrong coz -> attributes are const; assignment doesn't make sense! 
	// {
	// 	x = copy.x;
	// 	y = copy.y;
	// }
	(void)copy; // * basically do nothing
	return (*this);
}

Point::~Point() {}																					// * Destructor

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}
