/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:58:57 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/11 21:18:22 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
		int					fxd_p_value;		// stores fixed point value
		static const int	frct_bits = 8;		// number of fractional bits = 8
public:
		// * Orthodox Canonical Form (OCF)
		Fixed();								// constuctor
		Fixed(const Fixed &copy); 				// cp constructor
		Fixed &operator = (const Fixed &copy);	// cp assignment operator
		~Fixed();								// destructor

		int getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif // !FIXED_HPP
