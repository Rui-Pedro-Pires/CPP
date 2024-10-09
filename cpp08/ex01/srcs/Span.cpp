/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:39:34 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 19:39:34 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"

Span::Span() : maxSize(0)
{
}

Span::Span(unsigned int N) : maxSize(N)
{
}

Span::~Span()
{
}

Span::Span(const Span &other) : maxSize(other.maxSize)
{
    this->vec = other.vec;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->maxSize = other.maxSize;
        this->vec = other.vec;
    }
    return *this;
}

void Span::addNumber(int toAdd)
{
    if (this->vec.size() == this->maxSize)
        throw SizeOverflowException();
    this->vec.push_back(toAdd);
}

void Span::addManyNumbers(std::vector<int> vec)
{
    if (this->vec.size() == this->maxSize || this->vec.size() + vec.size() > this->maxSize)
        throw SizeOverflowException();
    this->vec.insert(this->vec.end(), vec.begin(), vec.end());
}

int Span::shortestSpan()
{
    int min_dist = 2147483647;
    int diff;
    int size = this->vec.size();
    if (size <= 1)
        throw NoElementsEnoughtException();
    std::sort(this->vec.begin(), this->vec.end());
    for (int i = 0; i < size - 1; i++)
    {
        diff = abs(this->vec[i] - this->vec[i + 1]);
        if (diff < min_dist)
            min_dist = diff;
    }
    return min_dist;
}

int Span::longestSpan()
{
    int size = this->vec.size();
    if (size <= 1)
        throw NoElementsEnoughtException();
    std::sort(this->vec.begin(), this->vec.end());
    return abs(this->vec[0] - this->vec[size - 1]);
}

const char *Span::SizeOverflowException::what() const throw()
{
    return "No space enought to add elements";
}

const char *Span::NoElementsEnoughtException::what() const throw()
{
    return "No elements enought to check";
}