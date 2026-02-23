#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief Determines if a number is a Digitorial Permutation.
 * 
 * A Digitorial Permutation is a number where the sum of factorials of its digits,
 * when sorted, produces a permutation of the original number's digits.
 * 
 * Example: If n = 145, then 1! + 4! + 5! = 1 + 24 + 120 = 145
 * The digits of 145 are [1, 4, 5] and the digits of 145 are [1, 4, 5],
 * so 145 is a Digitorial Permutation.
 */

/**
 * @brief Computes the factorial of a non-negative integer.
 * 
 * @param n The non-negative integer whose factorial is to be computed.
 * @return The factorial of n as a long long integer.
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
long long fact(int n);

/**
 * @brief Checks if a number is a Digitorial Permutation.
 * 
 * Calculates the sum of factorials of all digits in the number,
 * then compares the sorted digits of the original number with the
 * sorted digits of the factorial sum.
 * 
 * @param n The integer to check.
 * @return True if n is a Digitorial Permutation, false otherwise.
 * 
 * Time Complexity: O(d * d) where d is the number of digits
 * Space Complexity: O(d) for storing string representations
 */
bool isDigitorialPermutation(int n);
class Solution
{
public:
    long long fact(int n)
    {
        if (n == 0)
            return 1;
        long long val = 1;

        while (n >= 1)
        {
            val = val * n;
            n--;
        }
        return val;
    }

public:
    bool isDigitorialPermutation(int n)
    {
        string temp = to_string(n);

        long long sum = 0;

        while (n)
        {
            sum += fact(n % 10);
            n = n / 10;
        }
        string str = to_string(sum);

        sort(temp.begin(), temp.end());
        sort(str.begin(), str.end());

        return temp == str;
    }
};