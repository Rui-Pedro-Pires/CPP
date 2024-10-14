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

#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <bits/stdc++.h>
#include <iostream>

template <typename T>
class PmergeMe
{
private:
    T main;
    T pend;
    clock_t start;
    clock_t end;

private:
    void merge(int left, int mid, int right);
    void binaryInsert(int left, int right, int number);
    bool ft_isdigit(std::string str);

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void mergeSort(int left, int right);
    void insert(void);

    std::vector<int> parseNumbers(char **argv);
    void initValues(std::vector<int> numbers);
    size_t jacobthal(size_t n);
    int getSizeMain() const;
    void printBeforeSort(std::vector<int> numbers);
    void printAfterSort();
    void initTime();
    void closeTime();
    void getTimeToSort();

    class BadNumbersException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

#include "PmergeMe.tpp"

#endif