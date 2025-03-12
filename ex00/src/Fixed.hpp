/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:58:57 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/12 11:10:04 by cmakario         ###   ########.fr       */
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
		Fixed &operator = (const Fixed &copy);	// Cp assignment operator
		~Fixed();								// Destructor

		void setRawBits(int const raw);			// Setter
		int getRawBits(void) const;				// Getter
};

#endif // !FIXED_HPP
