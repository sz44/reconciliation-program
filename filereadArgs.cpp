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

    int target;

    std::ifstream input_file_2(argv[2], std::ifstream::in);
    if (!input_file_2.is_open())
    {
        std::cerr << "could not open input file '" << argv[2] << "'!\n";
        return EXIT_FAILURE;
    }

    double t;
    input_file_2 >> t;
    t *= 100;
    target = t;

    estimateTime(nums, target);

    clock_t start_time = clock();
    auto table = subsetSumTable(nums, target);
    clock_t stop_time = clock();
    std::cout << "Time taken: " << double(stop_time - start_time) / CLOCKS_PER_SEC << " seconds\n";

    start_time = clock();
    auto solution = subsetSum(table, nums, target);
    stop_time = clock();
    std::cout << "Time taken: " << double(stop_time - start_time) / CLOCKS_PER_SEC << " seconds\n";

    std::vector<double> solution_d;

    for (auto n: solution) {
        double d = n / 100.0;
        solution_d.push_back(d);
    }

    double total = 0;
    std::cout << '[';
    for (const auto &n:solution_d) {
        total += n;
        std::cout << n << ", ";
    }
    std::cout << "]\n";

    std::cout << total << "\n";

    return EXIT_SUCCESS;
}