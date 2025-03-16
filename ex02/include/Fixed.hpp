/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:58:57 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/15 21:48:01 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>


class Fixed
{
private:
		int					fixedPointValue;	// Stores fixed point value
		static const int	frct_bits = 8;		// Number of fractional bits = 8
public:
		// * Orthodox Canonical Form (OCF)
		Fixed();								// Constuctor
		Fixed(const Fixed &copy); 				// Cp constructor
		Fixed &operator= (const Fixed &copy);	// Cp assignment operator
		~Fixed();								// Destructor
		// ---ex01----
		Fixed(const int);						// Constuctor with parameter
		Fixed(const float);						// Constuctor with parameter
		// ----------- ------------------
		void setRawBits(int const raw);			// Setter
		int getRawBits(void) const;				// Getter
		// ---ex01----
		float toFloat(void) const;
		int	toInt(void) const;	

		//* overload -> << 
		friend std::ostream &operator<< (std::ostream &os, const Fixed &obj);
		// ---ex02---- *More overloads
		bool operator> (const Fixed &obj) const;
		bool operator< (const Fixed &obj) const;
		bool operator>= (const Fixed &obj) const;
		bool operator<= (const Fixed &obj) const;
		bool operator== (const Fixed &obj) const;
		bool operator!= (const Fixed &obj) const;

		Fixed operator+ (const Fixed &obj) const;
		Fixed operator- (const Fixed &obj) const;
		Fixed operator* (const Fixed &obj) const;
		Fixed operator/ (const Fixed &obj) const;

		// // TODO : do not know yet how to implement this one
		Fixed &operator++();		// pre-increment (++x)
		Fixed operator++(int);		// post-increment (x++) // dummy int parameter, returns by value
		Fixed &operator--();		// pre-decrement (--x)
		Fixed operator--(int);		// post-increment(x--) // dummy int parameter, returns by value

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);
	};

	// std::ostream &operator<< (std::ostream &os, const Fixed &obj);

#endif // !FIXED_HPP
