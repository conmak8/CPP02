/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:40:29 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/15 15:38:09 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Point.hpp"


int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside_point(1, 1);
	Point outside_point(11, 11);

	std::cout << "Inside (1): " << bsp(a, b, c, inside_point) << std::endl;		// expect true
	std::cout << "Outside: " << bsp(a, b, c, outside_point) << std::endl;		// expect false (0)

	return 0;
}
