/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:58:57 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/12 15:57:43 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class Fixed
{
private:
		int					fxd_p_value;		// Stores fixed point value
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
		// -----------
		void setRawBits(int const raw);			// Setter
		int getRawBits(void) const;				// Getter
		// ---ex01----
		float toFloat(void) const;
		int	toInt(void) const;	

		//TODO overload << ?
		friend std::ostream &operator<< (std::ostream &os, const Fixed &obj); // ? why friend??alliw exw
};

#endif // !FIXED_HPP
