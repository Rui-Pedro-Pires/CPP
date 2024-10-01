/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:07:23 by ruiolive          #+#    #+#             */
/*   Updated: 2024/09/30 15:00:49 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main()
{
    try
    {
        Bureaucrat ze("ze", 30);
        std::cout << ze << std::endl;
        Form man("man", 50, 50);
        std::cout << man << std::endl;
        ze.signForm(man);
        std::cout << man << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        Bureaucrat manuel("manuel", 60);
        std::cout << manuel << std::endl;
        Form meme("meme", 50, 50);
        std::cout << meme << std::endl;
        manuel.signForm(meme);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}