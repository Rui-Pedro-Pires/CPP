/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:22:58 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/12 12:04:56 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:31:01 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/07 21:31:01 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <bits/stdc++.h>

#include <iostream>

class PmergeMe
{
private:
    std::vector<int> main;
    std::vector<int> pend;

public:
    PmergeMe( std::vector<int> numbers );
    PmergeMe( const PmergeMe& other );
    PmergeMe& operator=( const PmergeMe& other );
    ~PmergeMe();

    void mergeSort( int left, int right );
    void merge( int left, int mid, int right );
    void inserting( void );
    void binaryInsert( int left, int right, int number );

    int getSizeMain() const;
    int getSizePend() const;
    void printList( std::string what );
};

#endif