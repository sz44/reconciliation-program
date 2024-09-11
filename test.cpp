#include <iostream>
#include <vector>
#include "subsetSums.h"

int main() {
    // auto nums = std::vector<int>{-1,3,5,-2,8};
    // auto k = 7;
    // auto nums = std::vector<int>{18, 52, 72, 92, 76, -83, 19, 74, -25, 69};
    // auto k = 100;

    auto [nums,k] = generateTestData(100, 1000000); 
    std::cout << "target: " << k << std::endl;

    for (const auto &i : nums)
    {
        std::cout << i << ", ";
    }
    std::cout << "\n";

    auto e = estimateTime(nums,k);
    std::cout << "estimated time: " << e << std::endl;

    clock_t start_time = clock();
    auto table = subsetSumTable(nums, k);
    clock_t stop_time = clock();
    std::cout << "Time taken: " << double(stop_time - start_time) / CLOCKS_PER_SEC << " seconds\n";

    start_time = clock();
    auto solution = subsetSum(table, nums, k);
    stop_time = clock();
    std::cout << "Time taken: " << double(stop_time - start_time) / CLOCKS_PER_SEC << " seconds\n";

    std::cout << "[ ";
    for (const auto &n:solution) {
        std::cout << n << ", ";
    }
    std::cout << "]\n";
    return 0;
}