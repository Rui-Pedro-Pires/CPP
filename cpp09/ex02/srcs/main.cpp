#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
    clock_t start, end;

    if (argc < 2)
        return (0);
    try
    {
        PmergeMe num(argv);

        start = clock();
        num.mergeSort(0, num.getSizeMain() - 1);
        num.insert();
        end = clock();

        std::cout << "After: ";
        num.printList("main");
        std::cout << std::endl;

        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        std::cout << "Time to process a range of 200 elements with std::vector : " << std::fixed
                  << time_taken << std::setprecision(5) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
