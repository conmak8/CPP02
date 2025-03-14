/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmakario <cmakario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:40:29 by cmakario          #+#    #+#             */
/*   Updated: 2025/03/14 15:26:44 by cmakario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"


int main() {
    Fixed a(12.34f);
    Fixed b(56.78f);

    std::cout << "min: " << Fixed::min(a, b) << std::endl;
    std::cout << "max: " << Fixed::max(a, b) << std::endl;

    Fixed const c(123.256f);
    Fixed const d(1234.5678f);

    std::cout << "const min: " << Fixed::min(c, d) << std::endl;
    std::cout << "const max: " << Fixed::max(c, d) << std::endl;

    return 0;
}
