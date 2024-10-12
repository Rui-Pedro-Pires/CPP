/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:49:49 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/12 11:49:49 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(const RPN &other)
{
    this->stack = other.stack;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        this->stack = other.stack;
    }
    return *this;
}

bool RPN::ft_isdigit(std::string &str)
{
    int i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

void RPN::doRPN(std::string input)
{
    std::stringstream ss(input);
    std::string word;
    int result;
    while (!ss.eof())
    {
        std::getline(ss, word, ' ');
        if (word == "+" || word == "-" || word == "*" || word == "/")
        {
            if (this->stack.size() < 2)
                throw BadOrderException();
            int second = this->stack.top();
            this->stack.pop();
            int first = this->stack.top();
            this->stack.pop();
            if (word == "+")
                result = first + second;
            else if (word == "-")
                result = first - second;
            else if (word == "*")
                result = first * second;
            else
                result = first / second;
            this->stack.push(result);
        }
        else if (ft_isdigit(word))
        {
            long num = strtol(word.c_str(), NULL, 10);
            if (num > -10 && num < 10)
                this->stack.push(num);
            else
                throw BadNumberException();
        }
        else
        {

            throw BadCharactersException();
        }
    }
    if (this->stack.size() != 1)
        throw BadCharactersException();
    std::cout << this->stack.top() << std::endl;
}

const char *RPN::BadCharactersException::what() const throw()
{
    return "Wrong characters input!";
}

const char *RPN::BadOrderException::what() const throw()
{
    return "Wrong order character input!";
}

const char *RPN::BadNumberException::what() const throw()
{
    return "Wrong number character input!";
}
