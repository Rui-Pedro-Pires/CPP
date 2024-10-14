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

template <>
PmergeMe<std::vector<int> >::PmergeMe()
{
}

template <>
PmergeMe<std::deque<int> >::PmergeMe()
{
}


template <>
PmergeMe<std::vector<int> >::~PmergeMe()
{
}

template <>
PmergeMe<std::deque<int> >::~PmergeMe()
{
}

template <>
PmergeMe<std::vector<int> >::PmergeMe(const PmergeMe &other)
{
    this->main = other.main;
    this->pend = other.pend;
}

template <>
PmergeMe<std::deque<int> >::PmergeMe(const PmergeMe &other)
{
    this->main = other.main;
    this->pend = other.pend;
}

template <>
PmergeMe<std::vector<int> > &PmergeMe<std::vector<int> >::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->main = other.main;
        this->pend = other.pend;
    }
    return *this;
}

template <>
PmergeMe<std::deque<int> > &PmergeMe<std::deque<int> >::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        this->main = other.main;
        this->pend = other.pend;
    }
    return *this;
}


template <>
bool PmergeMe<std::vector<int> >::ft_isdigit(std::string str)
{
    std::string::iterator itr;
    for (itr = str.begin(); itr < str.end(); itr++)
    {
        if (!isdigit(*itr))
            return (false);
    }
    return (true);
}

template <>
bool PmergeMe<std::deque<int> >::ft_isdigit(std::string str)
{
    std::string::iterator itr;
    for (itr = str.begin(); itr < str.end(); itr++)
    {
        if (!isdigit(*itr))
            return (false);
    }
    return (true);
}

template <>
std::vector<int> PmergeMe<std::vector<int> >::parseNumbers(char **argv)
{
    int i = 1;
    long num;
    std::vector<int> numbers;
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

template <>
std::vector<int> PmergeMe<std::deque<int> >::parseNumbers(char **argv)
{
    int i = 1;
    long num;
    std::vector<int> numbers;
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

template <>
void PmergeMe<std::vector<int> >::initValues(std::vector<int> numbers)
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


template <>
void PmergeMe<std::deque<int> >::initValues(std::vector<int> numbers)
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
template <>
int PmergeMe<std::vector<int> >::getSizeMain() const
{
    return this->main.size();
}

template <>
int PmergeMe<std::deque<int> >::getSizeMain() const
{
    return this->main.size();
}

template <>
void PmergeMe<std::vector<int> >::merge(int left, int mid, int right)
{
    std::vector<int> LMain(this->main.begin() + left, this->main.begin() + mid + 1);
    std::vector<int> RMain(this->main.begin() + mid + 1, this->main.begin() + right + 1);
    std::vector<int> LPend(this->pend.begin() + left, this->pend.begin() + mid + 1);
    std::vector<int> RPend(this->pend.begin() + mid + 1, this->pend.begin() + right + 1);

    std::vector<int>::iterator itBeginMain = this->main.begin() + left;
    std::vector<int>::iterator itBeginPend = this->pend.begin() + left;
    std::vector<int>::iterator itLMain = LMain.begin();
    std::vector<int>::iterator itLPend = LPend.begin();
    std::vector<int>::iterator itRMain = RMain.begin();
    std::vector<int>::iterator itRPend = RPend.begin();

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

template <>
void PmergeMe<std::deque<int> >::merge(int left, int mid, int right)
{
    std::deque<int> LMain(this->main.begin() + left, this->main.begin() + mid + 1);
    std::deque<int> RMain(this->main.begin() + mid + 1, this->main.begin() + right + 1);
    std::deque<int> LPend(this->pend.begin() + left, this->pend.begin() + mid + 1);
    std::deque<int> RPend(this->pend.begin() + mid + 1, this->pend.begin() + right + 1);

    std::deque<int>::iterator itBeginMain = this->main.begin() + left;
    std::deque<int>::iterator itBeginPend = this->pend.begin() + left;
    std::deque<int>::iterator itLMain = LMain.begin();
    std::deque<int>::iterator itLPend = LPend.begin();
    std::deque<int>::iterator itRMain = RMain.begin();
    std::deque<int>::iterator itRPend = RPend.begin();

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

template <>
void PmergeMe<std::vector<int> >::mergeSort(int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

template <>
void PmergeMe<std::deque<int> >::mergeSort(int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

template <>
void PmergeMe<std::vector<int> >::binaryInsert(int left, int right, int number)
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

template <>
void PmergeMe<std::deque<int> >::binaryInsert(int left, int right, int number)
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

template <>
void PmergeMe<std::vector<int> >::insert(void)
{
    if (this->pend.empty())
        return;
    this->main.insert(this->main.begin(), this->pend.front());
    size_t insertCounter = 1;
    size_t i = 1;
    while (i < this->pend.size())
    {
        if (i + insertCounter >= this->main.size())
            binaryInsert(0, this->main.size() - 1, this->pend[i]);
        else
            binaryInsert(0, i + insertCounter, this->pend[i]);
        insertCounter++;
        i++;
    }
}

template <>
void PmergeMe<std::deque<int> >::insert(void)
{
    if (this->pend.empty())
        return;
    this->main.insert(this->main.begin(), this->pend.front());
    size_t insertCounter = 1;
    size_t i = 1;
    while (i < this->pend.size())
    {
        if (i + insertCounter >= this->main.size())
            binaryInsert(0, this->main.size() - 1, this->pend[i]);
        else
            binaryInsert(0, i + insertCounter, this->pend[i]);
        insertCounter++;
        i++;
    }
}

template <>
void PmergeMe<std::vector<int> >::printBeforeSort(std::vector<int> numbers)
{
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <>
void PmergeMe<std::deque<int> >::printBeforeSort(std::vector<int> numbers)
{
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <>
void PmergeMe<std::vector<int> >::printAfterSort()
{
    std::cout << "After: ";
    for (std::vector<int>::iterator it = this->main.begin(); it != this->main.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <>
void PmergeMe<std::deque<int> >::printAfterSort()
{
    std::cout << "After: ";
    for (std::deque<int>::iterator it = this->main.begin(); it != this->main.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <>
void PmergeMe<std::vector<int> >::initTime()
{
    this->start = clock();
}

template <>
void PmergeMe<std::deque<int> >::initTime()
{
    this->start = clock();
}

template <>
void PmergeMe<std::vector<int> >::closeTime()
{
    this->end = clock();
}

template <>
void PmergeMe<std::deque<int> >::closeTime()
{
    this->end = clock();
}

template <>
void PmergeMe<std::vector<int> >::getTimeToSort()
{
    double time_taken = double(this->end - this->start);
        std::cout << "Time to process a range of " << this->main.size() << " elements with std::vector : " << std::fixed
                  << time_taken << std::setprecision(5) << " us" << std::endl;
}

template <>
void PmergeMe<std::deque<int> >::getTimeToSort()
{
    double time_taken = double(this->end - this->start);
        std::cout << "Time to process a range of " << this->main.size() << " elements with std::deque : " << std::fixed
                  << time_taken << std::setprecision(5) << " us" << std::endl;
}

template <>
const char* PmergeMe<std::vector<int> >::BadNumbersException::what() const throw()
{
    return "Error";
}


template <>
const char* PmergeMe<std::deque<int> >::BadNumbersException::what() const throw()
{
    return "Error";
}
