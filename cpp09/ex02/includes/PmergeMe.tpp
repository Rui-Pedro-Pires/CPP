/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiolive  <ruiolive@student.42.fr   >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 12:05:09 by ruiolive          #+#    #+#             */
/*   Updated: 2024/10/12 12:05:09 by ruiolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
PmergeMe<T>::PmergeMe()
{
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &other)
{
    this->main = other.main;
    this->pend = other.pend;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->main = other.main;
        this->pend = other.pend;
    }
    return *this;
}

template <typename T>
T PmergeMe<T>::parseNumbers(char **argv)
{
    int i = 1;
    long num;
    T numbers;
    while (argv[i])
    {
        if (!ft_isdigit(argv[i]))
            throw BadNumbersException();
        num = strtol(argv[i], NULL, 10);
        if (num < -INT_MAX || num > INT_MAX)
            throw BadNumbersException();
        numbers.push_back(num);
        i++;
    }
    return numbers;
}

template <typename T>
void PmergeMe<T>::initValues(T numbers)
{
    for (size_t i = 0; i < numbers.size(); i += 2)
    {
        if (i == numbers.size() - 1)
        {
            this->pend.push_back(numbers[i]);
            return;
        }
        if (numbers[i] >= numbers[i + 1])
        {
            this->main.push_back(numbers[i]);
            this->pend.push_back(numbers[i + 1]);
        }
        else
        {
            this->main.push_back(numbers[i + 1]);
            this->pend.push_back(numbers[i]);
        }
    }
}

template <typename T>
int PmergeMe<T>::getSizeMain() const
{
    return this->main.size();
}

template <typename T>
void PmergeMe<T>::merge(int left, int mid, int right)
{
    T LMain(this->main.begin() + left, this->main.begin() + mid + 1);
    T RMain(this->main.begin() + mid + 1, this->main.begin() + right + 1);
    T LPend(this->pend.begin() + left, this->pend.begin() + mid + 1);
    T RPend(this->pend.begin() + mid + 1, this->pend.begin() + right + 1);

    typename T::iterator itBeginMain = this->main.begin() + left;
    typename T::iterator itBeginPend = this->pend.begin() + left;
    typename T::iterator itLMain = LMain.begin();
    typename T::iterator itLPend = LPend.begin();
    typename T::iterator itRMain = RMain.begin();
    typename T::iterator itRPend = RPend.begin();

    while (itLMain != LMain.end() && itRMain != RMain.end() && itLPend != LPend.end() && itRPend != RPend.end())
    {
        if (*itLMain <= *itRMain)
        {
            *itBeginMain = *itLMain;
            *itBeginPend = *itLPend;
            itLMain++;
            itLPend++;
        }
        else
        {
            *itBeginMain = *itRMain;
            *itBeginPend = *itRPend;
            itRMain++;
            itRPend++;
        }
        itBeginMain++;
        itBeginPend++;
    }

    while (itLMain != LMain.end() && itLPend != LPend.end())
    {
        *itBeginMain = *itLMain;
        *itBeginPend = *itLPend;
        itLMain++;
        itLPend++;
        itBeginMain++;
        itBeginPend++;
    }

    while (itRMain != RMain.end() && itRPend != RPend.end())
    {
        *itBeginMain = *itRMain;
        *itBeginPend = *itRPend;
        itRMain++;
        itRPend++;
        itBeginMain++;
        itBeginPend++;
    }
}

template <typename T>
void PmergeMe<T>::mergeSort(int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

template <typename T>
void PmergeMe<T>::binaryInsert(int left, int right, int number)
{
    if (left >= right)
    {
        if (this->main[left] > number)
            this->main.insert(this->main.begin() + left, number);
        else
            this->main.insert(this->main.begin() + left + 1, number);
        return;
    }

    int mid = left + (right - left) / 2;

    if (this->main[mid] == number)
    {
        this->main.insert(this->main.begin() + mid, number);
        return;
    }
    else if (number > this->main[mid])
        return binaryInsert(mid + 1, right, number);
    else
        return binaryInsert(left, mid, number);
}

template <typename T>
void PmergeMe<T>::insert(void)
{
    if (this->pend.empty())
        return;
    this->main.insert(this->main.begin(), this->pend.front());
    size_t i = 0;
    size_t jacobIndex = 1;
    size_t distanceIndex = jacobthal(jacobIndex) * 2;
    size_t numberInsert = 1;
    while (i + distanceIndex < this->pend.size())
    {
        size_t start = i;
        i += distanceIndex;
        while (i > start)
        {
            binaryInsert(0, i + numberInsert - 1, this->pend[i]);
            numberInsert++;
            i--;
        }
        i += distanceIndex;
        jacobIndex++;
        distanceIndex = jacobthal(jacobIndex) * 2;
    }

    size_t start = i;
    i = this->pend.size() - 1;
    while (i > start)
    {
        binaryInsert(0, i + numberInsert - 1, this->pend[i]);
        numberInsert++;
        i--;
    }
}

template <typename T>
void PmergeMe<T>::printBeforeSort(T numbers)
{
    std::cout << "Before: ";
    for (typename T::iterator it = numbers.begin(); it != numbers.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::printAfterSort()
{
    std::cout << "After: ";
    for (typename T::iterator it = this->main.begin(); it != this->main.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::initTime()
{
    this->start = clock();
}

template <typename T>
void PmergeMe<T>::closeTime()
{
    this->end = clock();
}

template <typename T>
void PmergeMe<T>::getTimeToSort()
{
    double time_taken = double(this->end - this->start);
    std::cout << "Time to process a range of " << this->main.size() << " elements with std::vector : " << std::fixed
              << time_taken << std::setprecision(5) << " us" << std::endl;
}

template <typename T>
const char *PmergeMe<T>::BadNumbersException::what() const throw()
{
    return "Error";
}
