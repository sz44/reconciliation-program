// ./filereadArgs.cpp number.txt sums.txt
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include "subsetSumsClass.h"

int main(int argc, char *argv[])
{
#ifdef _DEBUG
    std::copy(argv, argv + argc, std::ostream_iterator<char *>(std::cout, "\n"));
#endif

    if (argc < 3)
    {
        std::cerr << "missing input file!\n";
        std::cerr << "usage: program.exe <input_file1> <input_file2> ...\n";
        return EXIT_FAILURE;
    }

    std::vector<int> nums;

    std::ifstream input_file_1(argv[1], std::ifstream::in);
    if (!input_file_1.is_open())
    {
        std::cerr << "could not open input file '" << argv[1] << "'!\n";
        return EXIT_FAILURE;
    }

    double n;
    while (input_file_1 >> n) {
        n *= 100;
        nums.push_back(n);
    }

    std::vector<int> targets;

    std::ifstream input_file_2(argv[2], std::ifstream::in);
    if (!input_file_2.is_open())
    {
        std::cerr << "could not open input file '" << argv[2] << "'!\n";
        return EXIT_FAILURE;
    }

    double t;
    while (input_file_2 >> t) {
        n *= 100;
        targets.push_back(n);
    }

    auto e = estimateTimeMulti(nums, targets);
    std::cout << "Estimate time: " << e << " seconds\n";

    clock_t start_time = clock();
    for (const auto &target: targets) {
        auto table = subsetSumTable(nums, target);
        auto solution = subsetSum(table, nums, target);
        auto curr = toCurrency(solution);
        printSolution(target, curr);
    }
    clock_t stop_time = clock();
    std::cout << "Time taken: " << double(stop_time - start_time) / CLOCKS_PER_SEC << " seconds\n";

    return EXIT_SUCCESS;
}