/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:20:29 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/11 21:59:07 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : fxd_p_value(0) // * Constructor
{
	std::cout << "Default constructor called" << std::endl;
}

// Fixed::Fixed(const Fixed &copy) : fxd_p_value(copy.fxd_p_value) { *this = copy; }; // ? Copy constructor  is the same which is better?

Fixed::Fixed(const Fixed &copy) : fxd_p_value(copy.fxd_p_value) {} // * Copy constructor

Fixed &Fixed::operator = (const Fixed &copy) // * Copy assignment operator
{		
	if (this == &copy)
	{
		std::cout << "Self assignment detected, skipping copy";
		return *this;
	}
	fxd_p_value = copy.fxd_p_value; // The same : this->fxd_p_value = copy.fxd_p_value;
	return *this;
}

Fixed::~Fixed() // *Destructor
{
	std::cout << "Destructor constructor called" << std::endl;	
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
