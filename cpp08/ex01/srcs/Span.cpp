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

Span::Span() : maxSize( 0 )
{
}

Span::Span( unsigned int N ) : maxSize( N )
{
}

Span::~Span()
{
}

Span::Span( const Span& other ) : maxSize( other.maxSize )
{
    int size = other.vec.size();
    for ( int i = 0; i < size; i++ )
    {
        this->vec.push_back( other.vec[i] );
    }
}

Span& Span::operator=( const Span& other )
{
    int size = other.vec.size();
    if ( this != &other )
    {
        this->maxSize = other.maxSize;
        this->vec.clear();
        for ( int i = 0; i < size; i++ )
        {
            this->vec.push_back( other.vec[i] );
        }
    }
    return *this;
}

void Span::addNumber( int toAdd )
{
    if ( this->vec.size() == this->maxSize )
        throw SizeOverflowException();
    this->vec.push_back( toAdd );
}

void Span::addManyNumbers( int* arr, int N )
{
    if ( this->vec.size() == this->maxSize )
        throw SizeOverflowException();
    this->vec.insert( this->vec.end(), arr, arr + N );
}

int Span::shortestSpan()
{
    int min_dist = 2147483647;
    int diff;
    int size = this->vec.size();
    if ( size <= 1 )
        throw NoElementsEnoughtException();
    for ( int i = 0; i < size - 1; i++ )
    {
        diff = abs( this->vec[i] - this->vec[i + 1] );
        if ( diff < min_dist )
            min_dist = diff;
    }
    return min_dist;
}

int Span::longestSpan()
{
    int max_dist = -2147483647;
    int diff;
    int size = this->vec.size();
    if ( size <= 1 )
        throw NoElementsEnoughtException();
    for ( int i = 0; i < size - 1; i++ )
    {
        diff = abs( this->vec[i] - this->vec[i + 1] );
        if ( diff > max_dist )
            max_dist = diff;
    }
    return max_dist;
}

const char* Span::SizeOverflowException::what() const throw()
{
    return "No space left to add elements";
}

const char* Span::NoElementsEnoughtException::what() const throw()
{
    return "No elements enought to check";
}