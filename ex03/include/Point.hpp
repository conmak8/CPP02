/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:52:50 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/15 12:48:39 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
class Point
{
private:
		Fixed const	x;
		Fixed const	y;
public:
		Point();											// Constructor
		Point(const float xValue, const float yValue);		// Constructor with parameters
		Point(const Point &copy);							// Copy constructor
		Point &operator= (const Point &copy);				// Copy assignment
		~Point();											// Destructor

		// * Getters
		Fixed getX() const;
		Fixed getY() const;
};

#endif // !POINT_HPP
