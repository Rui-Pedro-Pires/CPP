/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:05:09 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/12 12:05:09 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::PmergeMe( std::vector<int> numbers )
{
    for ( size_t i = 0; i < numbers.size(); i += 2 )
    {
        if ( i == numbers.size() - 1 )
        {
            this->pend.push_back( numbers[i] );
            return;
        }
        if ( numbers[i] >= numbers[i + 1] )
        {
            this->main.push_back( numbers[i] );
            this->pend.push_back( numbers[i + 1] );
        }
        else
        {
            this->main.push_back( numbers[i + 1] );
            this->pend.push_back( numbers[i] );
        }
    }
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe& other )
{
    this->main = other.main;
    this->pend = other.pend;
}

PmergeMe& PmergeMe::operator=( const PmergeMe& other )
{
    if ( this != &other )
    {
        this->main = other.main;
        this->pend = other.pend;
    }
    return *this;
}

void PmergeMe::printList( std::string what )
{
    std::vector<int>::iterator itMain = this->main.begin();
    std::vector<int>::iterator itPend = this->pend.begin();
    if ( what == "main" )
    {
        while ( itMain != this->main.end() )
        {
            std::cout << *itMain << " ";
            itMain++;
        }
    }
    else if ( what == "pend" )
    {
        while ( itPend != this->pend.end() )
        {
            std::cout << "pend: " << *itPend << std::endl;
            itPend++;
        }
    }
    else
    {
        while ( itMain != this->main.end() && itPend != this->pend.end() )
        {
            std::cout << "main: " << *itMain << std::endl;
            std::cout << "pend: " << *itPend << std::endl;
            itMain++;
            itPend++;
        }
        if ( itPend != this->pend.end() )
            std::cout << "pend: " << *itPend << std::endl;
    }
}

int PmergeMe::getSizeMain() const
{
    return this->main.size();
}

int PmergeMe::getSizePend() const
{
    return this->pend.size();
}

void PmergeMe::mergeSort( int left, int right )
{
    if ( left >= right )
        return;
    int mid = left + ( right - left ) / 2;
    mergeSort( left, mid );
    mergeSort( mid + 1, right );
    merge( left, mid, right );
}

void PmergeMe::merge( int left, int mid, int right )
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> LMain( this->main.begin() + left, this->main.begin() + mid + 1 );
    std::vector<int> RMain( this->main.begin() + mid + 1, this->main.begin() + right + 1 );
    std::vector<int> LPend( this->pend.begin() + left, this->pend.begin() + mid + 1 );
    std::vector<int> RPend( this->pend.begin() + mid + 1, this->pend.begin() + right + 1 );

    int i = 0, j = 0;
    int k = left;

    while ( i < n1 && j < n2 )
    {
        if ( LMain[i] <= RMain[j] )
        {
            this->main[k] = LMain[i];
            this->pend[k] = LPend[i];
            i++;
        }
        else
        {
            this->main[k] = RMain[j];
            this->pend[k] = RPend[j];
            j++;
        }
        k++;
    }

    while ( i < n1 )
    {
        this->main[k] = LMain[i];
        this->pend[k] = LPend[i];
        i++;
        k++;
    }

    while ( j < n2 )
    {
        this->main[k] = RMain[j];
        this->pend[k] = RPend[j];
        j++;
        k++;
    }
}

void PmergeMe::binaryInsert( int left, int right, int number )
{
    if ( left >= right )
    {
        if ( this->main[left] > number )
            this->main.insert( this->main.begin() + left, number );
        else
            this->main.insert( this->main.begin() + left + 1, number );
        return;
    }

    int mid = left + ( right - left ) / 2;

    if ( this->main[mid] == number )
    {
        this->main.insert( this->main.begin() + mid, number );
        return;
    }
    else if ( number > this->main[mid] )
        return binaryInsert( mid + 1, right, number );
    else
        return binaryInsert( left, mid, number );
}

void PmergeMe::insert( void )
{
    this->main.insert( this->main.begin(), this->pend.front() );
    size_t insertCounter = 1;
    size_t i = 1;
    while ( i < this->pend.size() )
    {
        if ( i + insertCounter >= this->main.size() )
            binaryInsert( 0, this->main.size() - 1, this->pend[i] );
        else
            binaryInsert( 0, i + insertCounter, this->pend[i] );
        insertCounter++;
        i++;
    }
}

// int jacobsthal( const int n )
// {
//     return ( std::pow( 2, n + 1 ) + std::pow( -1, n ) ) / 3;
// }

// void PmergeMe::inserting( void )
// {
//     size_t insertCounter = 1;
//     size_t i = 0;
//     size_t jacobsthal_idx = 1;

//     this->main.insert( this->main.begin(), this->pend.front() );

//     int distance_forward = 2 * jacobsthal( jacobsthal_idx );
//     while ( i + distance_forward >= this->pend.size() )
//     {
//         const size_t start = i;
//         i += distance_forward;
//         while ( i > start )
//         {
//             binaryInsert( 0, i + insertCounter - 1, this->pend[i] );
//             ++insertCounter;
//             --i;
//         }
//         i += distance_forward;
//         ++jacobsthal_idx;
//         distance_forward = 2 * jacobsthal( jacobsthal_idx );
//     }

//     const size_t start = i;
//     i = this->pend.size() - 1;
//     while ( i > start )
//     {
//         binaryInsert( 0, this->main.size() - 1, pend[i] );
//         --i;
//     }
// }