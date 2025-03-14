/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:40:29 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/14 10:18:51 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"


int main(void)
{

	Fixed a;
	// std::cout << "a is............... " << a << std::endl;
	Fixed const b(10); 
	Fixed const c(42.42f); 
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "\n------------------------" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "------------------------" << std::endl;
	
	std::cout << "------------------------" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl; 
	std::cout << "c is " << c.toInt() << " as integer" << std::endl; 
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	std::cout << "------------------------\n" << std::endl;

	return (0);
}
