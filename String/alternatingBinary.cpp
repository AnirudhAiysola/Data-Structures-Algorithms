#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Finds the minimum number of operations needed to make a binary string alternating.
 * 
 * This function takes a binary string and determines the minimum number of bit flips
 * required to convert it into one of two possible alternating patterns:
 * - Pattern 1: "010101..." (starting with '0')
 * - Pattern 2: "101010..." (starting with '1')
 * 
 * @param s A binary string consisting of '0' and '1' characters.
 * @return The minimum number of operations (bit flips) needed to make the string
 *         match one of the alternating patterns.
 * 
 * @complexity
 *   Time Complexity: O(n) where n is the length of the string.
 *   Space Complexity: O(n) for storing the two pattern strings.
 * 
 * @example
 *   Input: "0110"
 *   Output: 1 (convert to "0101" by flipping one bit)
 */
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        int ops1 = 0, ops2 = 0;

        /*
        Two possibilities -> "01010101010.... or 1010101010101...."
        */
        string p1 = "1",p2 = "0";

        for(int i=1;i<n;i++){
            p1 += p1[i-1] == '1' ? '0' : '1';
            p2 += p2[i-1] == '1' ? '0' : '1';
        }

        for(int i=0;i<n;i++){
            if(p1[i] != s[i]){
                ops1++;
            }
            if(p2[i] != s[i]){
                ops2++;
            }
        }
        return min(ops1,ops2);
    }
};