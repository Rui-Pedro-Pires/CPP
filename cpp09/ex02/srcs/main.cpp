#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    try
    {
        PmergeMe<std::vector<int> > num(argv);

        num.initTime();
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
        PmergeMe<std::deque<int> > num(argv);

        num.initTime();
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
}
