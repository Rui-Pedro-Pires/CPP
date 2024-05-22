/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:50:34 by ruiolive          #+#    #+#             */
/*   Updated: 2024/05/21 13:50:34 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed d;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed c(5.5f);
    bool diff;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    diff = a != c;
    std::cout << diff << std::endl;
    diff = a == c;
    std::cout << diff << std::endl;
    diff = a < c;
    std::cout << diff << std::endl;
    diff = a > c;
    std::cout << diff << std::endl;
    diff = a >= d;
    std::cout << diff << std::endl;
    diff = a <= d;
    std::cout << diff << std::endl;
    return 0;
}