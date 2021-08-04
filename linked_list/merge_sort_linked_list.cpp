// https://leetcode.com/problems/sort-list/

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
    // fast runner technique (O(N))
    ListNode *middleNode(ListNode *head)
    {
        ListNode *fast = head; // move forward by 2
        ListNode *slow = head; // move forward by 1

        while ((fast->next) != NULL && ((fast->next)->next) != NULL)
        {
            fast = (fast->next)->next;
            slow = slow->next;
        }

        return slow;
    }

    // O(N)
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // base case
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        // recursive step
        if (l1->val < l2->val)
            l1->next = mergeTwoLists(l1->next, l2);
        else
            l2->next = mergeTwoLists(l1, l2->next);

        // return min val node
        if (l1->val < l2->val)
            return l1;
        return l2;
    }

    // mergesort O(N*(log(N)))
    ListNode *sortList(ListNode *head)
    {
        // base case (empty or singleton list)
        if (head == NULL || (head->next) == NULL)
            return head;

        // find mid of
        ListNode *mid = middleNode(head);

        // break lists at mid
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = NULL;

        // recursive sort
        l1 = sortList(l1);
        l2 = sortList(l2);

        // merge
        return mergeTwoLists(l1, l2);
    }
};