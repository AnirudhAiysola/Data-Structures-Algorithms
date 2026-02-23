#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief Calculates the sum of prefix scores for an array of words using a Trie data structure.
 * 
 * A prefix score for a word is the count of how many words in the input array have that word as a prefix.
 * For each word, the score is the sum of counts across all its prefixes.
 * 
 * @details
 * - Uses a Trie (prefix tree) where each node tracks how many words pass through it
 * - Time Complexity: O(N * L) where N is the number of words and L is the average word length
 * - Space Complexity: O(N * L) for storing the Trie structure
 */

/**
 * @struct Node
 * @brief Trie node containing child pointers and metadata.
 * @param isEnd Boolean flag indicating if this node marks the end of a word
 * @param children Array of 26 pointers to child nodes (one for each lowercase letter)
 * @param count Number of words that pass through this node
 */

/**
 * @brief Inserts a word into the Trie and updates prefix counts.
 * @param str Reference to the string to be inserted
 * @details Creates nodes as needed and increments the count at each node along the path
 */

/**
 * @brief Calculates the prefix score for a given word.
 * @param str Reference to the string whose prefix score is to be calculated
 * @return The sum of counts across all prefixes of the word
 */

/**
 * @brief Computes prefix scores for all words in the input array.
 * @param words Reference to a vector of strings
 * @return A vector of integers where each element is the prefix score of the corresponding word
 */
class Solution
{
public:
    struct Node
    {
        bool isEnd;
        Node *children[26];
        int count = 0;
    };
    Node *root = new Node();
    void insertWord(string &str)
    {
        int n = str.size();
        Node *curr = root;

        for (int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';
            if (curr->children[idx] == NULL)
            {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
            curr->count++;
            if (i == str.size() - 1)
                curr->isEnd = true;
        }
        return;
    }
    int isPrefix(string &str)
    {
        int n = str.size();
        Node *curr = root;
        int count = 0;

        for (int i = 0; i < str.size(); i++)
        {
            int idx = str[i] - 'a';
            curr = curr->children[idx];
            count += curr->count;
        }
        return count;
    }

public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        int n = words.size();

        vector<int> result;

        for (int i = 0; i < n; i++)
        {
            insertWord(words[i]);
        }

        for (int i = 0; i < n; i++)
        {
            int count = isPrefix(words[i]);
            result.push_back(count);
        }
        return result;
    }
};