/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:20:29 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/12 11:10:05 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : fxd_p_value(0) // * Constructor
{
	std::cout << "Default constructor called" << std::endl;
}

// *in this case i have to call also the cp assignment operator :
// Fixed::Fixed(const Fixed &copy)
// { 
// 	std::cout << "Copy constructor called" << std::endl;
// 	\*this = copy;
// }; 

Fixed::Fixed(const Fixed &copy) : fxd_p_value(copy.fxd_p_value) // * Copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &copy) // * Copy assignment operator
{	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
	{
		std::cout << "Self assignment detected, skipping copy";
		return *this;
	}
	fxd_p_value = copy.getRawBits();
	// * fxd_p_value = copy.fxd_p_value; or this->fxd_p_value = copy.fxd_p_value;
	// they do the same job but in more complicated class the getRaw may want to check
	// inputs validity before return them.
	return *this;
}

Fixed::~Fixed() // *Destructor
{
	std::cout << "Destructor called" << std::endl;	
}

void Fixed::setRawBits(int const raw) // Setter
{
	this->fxd_p_value = raw;
}

int Fixed::getRawBits(void) const // Getter
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fxd_p_value);
}
