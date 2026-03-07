#include <bits/stdc++.h>
using namespace std;

/**
 * Solution class for the LeetCode problem: Minimum Operations to Make Array Alternating.
 * This problem involves finding the minimum number of changes to make an array alternating,
 * where elements at even indices differ from those at odd indices.
 * The approach uses frequency counting and greedy selection of most common values.
 */
class Solution
{
public:
    /**
     * Calculates the minimum operations required to make the array alternating.
     * We count frequencies of numbers at even and odd positions separately,
     * then choose the most frequent values for each, handling conflicts if they match.
     * @param nums The input vector of integers.
     * @return The minimum number of operations (changes) needed.
     */
    int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        // Edge case: single element array is already alternating
        if (n == 1)
            return 0;

        // Maps to count frequencies at even and odd indices
        unordered_map<int, int> evenCount, oddCount;

        // Iterate through the array and count frequencies based on index parity
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                evenCount[nums[i]]++;
            }
            else
            {
                oddCount[nums[i]]++;
            }
        }

        // Vectors to store pairs of (number, frequency) for sorting
        vector<pair<int, int>> evenData, oddData;

        // Populate evenData from evenCount map
        for (auto &it : evenCount)
        {
            evenData.push_back({it.first, it.second});
        }
        // Populate oddData from oddCount map
        for (auto &it : oddCount)
        {
            oddData.push_back({it.first, it.second});
        }

        // Sort the data in descending order of frequency
        sort(evenData.begin(), evenData.end(), [&](pair<int, int> &a, pair<int, int> &b)
             { return a.second > b.second; });
        sort(oddData.begin(), oddData.end(), [&](pair<int, int> &a, pair<int, int> &b)
             { return a.second > b.second; });

        // If the most frequent numbers for even and odd are different, use them
        if (evenData[0].first != oddData[0].first)
        {
            return n - (evenData[0].second + oddData[0].second);
        }

        // If they are the same, consider alternatives: second best for odd or even
        int secondOdd = oddData.size() > 1 ? oddData[1].second : 0;
        int secondEven = evenData.size() > 1 ? evenData[1].second : 0;
        int option1 = evenData[0].second + secondOdd;
        int option2 = oddData[0].second + secondEven;
        // Return the minimum operations by maximizing the kept elements
        return n - max(option1, option2);
    }
};