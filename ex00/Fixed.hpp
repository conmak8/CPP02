/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:58:57 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/11 21:05:58 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
		int	fxd_pnt_value;
		static const int n_frct_bits;
public:
		// constuctor
		// cp constructor
		// assignment operator constructor
		// destructor

		int getRawBits(void) const;
		void setRawBits(int const raw);
};


#endif // !FIXED_HPP
