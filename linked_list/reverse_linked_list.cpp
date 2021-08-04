// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode *iterativeReverse(ListNode *head)
    {
        ListNode *prev = NULL;
        while (head != NULL)
        {
            // store next
            ListNode *temp = head->next;

            // update current
            head->next = prev;

            // update prev
            prev = head;

            // move to next node
            head = temp;
        }

        // prev points to last node (new head)
        return prev;
    }

    ListNode *reverseList(ListNode *head)
    {
        // if iterative
        // return iterativeReverse(head);

        // last node
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *sHead = reverseList(head->next);

        // point each node to its prev node
        (head->next)->next = head;
        head->next = NULL;
        return sHead;
    }
};