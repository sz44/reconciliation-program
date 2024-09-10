#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

std::vector<std::vector<bool>> subsetSumTable(const std::vector<int> &nums, const int k) {
    auto minValItr = std::min_element(nums.begin(), nums.end());
    int minVal = *minValItr < 0 ? *minValItr : 0;
    int ROWS = nums.size() + 1;
    int COLS = std::abs(minVal) + k + 1;
    if (minVal < 0) {
        COLS += std::abs(minVal);
    } 
    std::vector<std::vector<bool>> dp(ROWS, std::vector<bool>(COLS,false));

    for (int row = 1; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            auto currentSum = col + minVal;
            auto b = currentSum == nums[row-1]; 

            auto c = dp[row-1][col];

            auto newCol = col - nums[row-1];
            auto isValidIndex = (0 <= newCol) && (newCol < COLS);
            auto d = isValidIndex && dp[row-1][newCol];

            dp[row][col] = b || c || d;
        }
    }

    return dp;
}

std::vector<int> subsetSum(const std::vector<std::vector<bool>> &table, const std::vector<int> &nums, const int k) {
    std::vector<int> res;
    auto minValItr = std::min_element(nums.begin(), nums.end());
    int minVal = *minValItr < 0 ? *minValItr : 0;
    int row = table.size() - 1;
    int col = table[0].size() - 1 + minVal;

    if (!table[row][col]) {
        return {};
    }

    // todo: run this first, then instead of passing table run sebsetSumTable() here, 
    //       then check table[row][col],
    for (int n : nums) {
        if (n == k) {
            return {n};
        }
    }

    while (row > 0 && col >= 0)
    {
        if (nums[row - 1] == col + minVal)
        {
            res.push_back(nums[row - 1]);
            break;
        }
        else if (table[row - 1][col])
        {
            --row;
        }
        else if (table[row - 1][col - nums[row - 1]]) // potential invalid index?
        {
            res.push_back(nums[row - 1]);
            col -= nums[row - 1];
            --row;
        }
    }
    return res;
}

void estimateTime(const std::vector<int>& nums, const int k) {
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k1 = 55;
    clock_t start_time = clock();
    subsetSumTable(nums1, k1);
    clock_t end_time = clock();
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    double mn = static_cast<double>(nums.size()) / 10;
    if (mn < 1) {
        mn = 1;
    }
    double mk = static_cast<double>(k) / 55;
    if (mk < 1) {
        mk = 1;
    }
    double estimate = elapsed_time * mn * mk;
    std::cout << "Estimate time: " << estimate << " seconds\n";
}

std::pair<std::vector<int>, int> generateTestData(int n, int k) {
    std::vector<int> nums(n);
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; ++i) {
        nums[i] = rand() % (2 * k + 1) - k;
    }
    return {nums, k};
}