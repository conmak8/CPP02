/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:20:29 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/14 18:11:43 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"


Fixed::Fixed() : fixedPointValue(0) 													// * Constructor
{
	std::cout << "Default constructor called" << std::endl;
}

// ----ex01----------------------------

Fixed::Fixed(const int integer)	: fixedPointValue(integer << frct_bits)					// * Constructor with paremeters Int
{
	std::cout << "Int constructor called" << std::endl;
}

// ! v.2
// Fixed::Fixed(const int integer)														// * Constructor with paremeters Int
// {
// 	std::cout << "Int constructor called" << std::endl;
// 	this->fixedPointValue = integer << frct_bits;
// }

Fixed::Fixed(const float fpoint) :	fixedPointValue(roundf(fpoint * (1 << frct_bits)))	// * Constructor with paremeters Float
{
	std::cout << "Float constructor called" << std::endl;
	// std::cout << "\nInput " << fpoint << std::endl;
	// std::cout << "output: " << fixedPointValue << std::endl;
}

// ! v.2
// Fixed::Fixed(const float fpoint) 													// * Constructor with paremeters Float
// {
// 	std::cout << "Float constructor called" << std::endl;
// 	fixedPointValue = (roundf(fpoint * (1 << frct_bits)));
// }

//------------------------------------------------------------------
Fixed::Fixed(const Fixed &copy) : fixedPointValue(copy.fixedPointValue)					// * Copy constructor
{
	std::cout << "Copy constructor called" << std::endl;
}

// *in this case i have to call also the cp assignment operator :						// * Copy constructor v.2
// Fixed::Fixed(const Fixed &copy)
// { 
// 	std::cout << "Copy constructor called" << std::endl;
// 	\*this = copy;
// }; 

Fixed &Fixed::operator= (const Fixed &copy) 											// * Copy assignment operator
{	
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
	{
		std::cout << "Self assignment detected, skipping copy";
		return *this;
	}
	fixedPointValue = copy.getRawBits();
	// * fixedPointValue = copy.fixedPointValue; or this->fixedPointValue = copy.fixedPointValue;
	// they do the same job but in more complicated class the getRaw may want to check
	// inputs validity before return them.
	return *this;
}

Fixed::~Fixed()																			// *Destructor
{
	std::cout << "Destructor called" << std::endl;	
}

// -------- Methods -----------------------------------------------
void Fixed::setRawBits(int const raw) // Setter
{
	this->fixedPointValue = raw;
}

int Fixed::getRawBits( void ) const // Getter
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointValue);
}

// ------- ex01 ---------------------------------------------------
float Fixed::toFloat(void) const
{
	return (static_cast<float>(fixedPointValue) / (1 << frct_bits)); // ! cast as to prevent trunctuation
}

int Fixed::toInt(void) const
{
	return (fixedPointValue >> frct_bits);
}

std::ostream &operator<< (std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return (os);
}

// ------- ex02 ---------------------------------------------------
// ------- > < >= <= == != ----------------------------------------
bool Fixed::operator> (const Fixed &obj) const
{
	return (this->fixedPointValue > obj.fixedPointValue);
}

bool Fixed::operator< (const Fixed &obj) const
{
	return (this->fixedPointValue < obj.fixedPointValue);
}

bool Fixed::operator>= (const Fixed &obj) const
{
	return (this->fixedPointValue >= obj.fixedPointValue);
}

bool Fixed::operator<= (const Fixed &obj) const
{
	return (this->fixedPointValue <= obj.fixedPointValue);
}

bool Fixed::operator== (const Fixed &obj) const
{
	return (this->fixedPointValue == obj.fixedPointValue);
}

bool Fixed::operator!= (const Fixed &obj) const
{
	return (this->fixedPointValue != obj.fixedPointValue);
}

// ----- + - * / --------------------------------------------------
Fixed Fixed::operator+ (const Fixed &obj) const
{
	Fixed result(this->toFloat() + obj.toFloat());
	return (result);
}

Fixed Fixed::operator- (const Fixed &obj) const
{
	Fixed result(this->toFloat() - obj.toFloat());
	return (result);}

Fixed Fixed::operator* (const Fixed &obj) const
{
	Fixed result(this->toFloat() * obj.toFloat());
	return (result);
}

Fixed Fixed::operator/ (const Fixed &obj) const
{
	if (obj.toFloat() == 0)
	{
		std::cerr << "🚨 Division by zero.💀💀💀💀💀💀💀💀";
		return (Fixed());
	}
	return (this->toFloat() / obj.toFloat());
}

// ------- min&max methods ------------------------------------------
// v.1 first implemantation before comparison overload
// Fixed &Fixed::min(Fixed &a, Fixed &b) 
// {
// 	if (a.getRawBits() < b.getRawBits())
// 		return (a);
// 	return (b);
// }

Fixed &Fixed::min(Fixed &a, Fixed &b) 
{
	return ((a < b) ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

// -------pre & post in/decrements-----------------------------------

Fixed &Fixed::operator++()		// pre-increment (++x)
{
	this->fixedPointValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int)		// post-increment (x++)
{
	Fixed temp(*this);
	++(*this);
	return (temp);
}

Fixed &Fixed::operator--()		// pre-decrement (--x)
{
	this->fixedPointValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int)		// post-increment (x--)
{
	Fixed temp(*this);
	--(*this);
	return (temp);
}
