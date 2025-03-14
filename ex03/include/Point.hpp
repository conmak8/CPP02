/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:52:50 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/14 19:19:27 by cmakario         ###   ########.fr       */
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
		Point(); //Constructor
		Point(const float x, const float y);
		Point(const Point &copy);
		Point &operator= (const Point &copy);
		~Point();

};

#endif // !POINT_HPP