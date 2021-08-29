// https://leetcode.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    // fast runner technique
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head; // move forward by 2
        ListNode *slow = head; // move forward by 1

        while ((fast->next) != NULL && ((fast->next)->next) != NULL)
        {
            fast = (fast->next)->next;
            slow = slow->next;
        }

        // if even nodes, move to n/2+1 node
        if ((fast->next) != NULL && ((fast->next)->next) == NULL)
            slow = slow->next;

        return slow;
    }
};