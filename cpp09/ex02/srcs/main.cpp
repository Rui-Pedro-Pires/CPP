/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:01:50 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/14 14:01:50 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (0);
    }
    try
    {
        PmergeMe<std::vector<int> > num;

        std::vector<int> numbers1 = num.parseNumbers(argv);
        num.printBeforeSort(numbers1);
        num.initTime();
        std::vector<int> numbers = num.parseNumbers(argv);
        num.initValues(numbers);
        num.mergeSort(0, num.getSizeMain() - 1);
        num.insert();
        num.closeTime();
        num.printAfterSort();
        num.getTimeToSort();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        PmergeMe<std::deque<int> > num;

        num.initTime();
        std::deque<int> numbers = num.parseNumbers(argv);
        num.initValues(numbers);
        num.mergeSort(0, num.getSizeMain() - 1);
        num.insert();
        num.closeTime();
        num.getTimeToSort();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
