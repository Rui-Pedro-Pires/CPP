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

public:
    PmergeMe(char **argv);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);
    void insert(void);
    void binaryInsert(int left, int right, int number);

    bool ft_isdigit(std::string str);
    std::vector<int> parseNumbers(char **argv);
    int getSizeMain() const;
    void initTime();
    void closeTime();
    void printAfterSort();
    void getTimeToSort();
};

#include "PmergeMe.tpp"

#endif