#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief Solution class for swapping nodes in a linked list.
 * 
 * This class provides functionality to swap the values of two nodes in a linked list.
 * The two nodes to be swapped are located at positions k and n-k+1 from the beginning
 * of the list, where n is the total length of the list.
 * 
 * @struct ListNode
 * @brief Node structure for the linked list.
 * @var val - Integer value stored in the node
 * @var next - Pointer to the next node in the list
 */

/**
 * @brief Retrieves the kth node from the given head node.
 * 
 * Traverses the linked list k times to find and return the kth node.
 * Note: This function assumes k is valid and within list bounds for proper behavior.
 * 
 * @param head Pointer to the head of the linked list
 * @param k The position of the node to retrieve (1-indexed)
 * @return Pointer to the kth node, or NULL if head is NULL or traversal ends before k steps
 * 
 * @time_complexity O(k) - linear traversal up to k nodes
 * @space_complexity O(1) - constant extra space
 */

/**
 * @brief Calculates the total number of nodes in the linked list.
 * 
 * Traverses the entire linked list to count all nodes.
 * 
 * @param head Pointer to the head of the linked list
 * @return The total count of nodes in the list, or 0 if head is NULL
 * 
 * @time_complexity O(n) - where n is the number of nodes in the list
 * @space_complexity O(1) - constant extra space
 */

/**
 * @brief Swaps the values of the kth node and the (n-k+1)th node in the linked list.
 * 
 * Uses a dummy node to simplify edge cases. Finds the kth node from the start and
 * the kth node from the end, then swaps their values.
 * 
 * @param head Pointer to the head of the linked list
 * @param k The position from the start of the list for the first node to swap (1-indexed)
 * @return Pointer to the head of the modified linked list
 * 
 * @time_complexity O(n) - two passes through the list to find nodes and calculate length
 * @space_complexity O(1) - constant extra space apart from dummy node
 */
class Solution
{
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int val)
        {
            this->val = val;
            next = NULL;
        }
    };

public:
    ListNode *getKthNode(ListNode *head, int k)
    {
        if (!head)
            return NULL;
        ListNode *curr = head;
        while (curr && k--)
        {
            curr = curr->next;
        }
        return curr;
    }
    int lengthOfList(ListNode *head)
    {
        if (!head)
            return 0;
        int count = 0;
        ListNode *curr = head;

        while (curr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }

public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (!head)
            return NULL;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        int count = lengthOfList(dummy);

        ListNode *node1 = getKthNode(dummy, k);
        ListNode *node2 = getKthNode(dummy, count - k);

        swap(node1->val, node2->val);

        return dummy->next;
    }
};