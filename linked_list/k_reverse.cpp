// https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    int countNodes(ListNode *curNode)
    {
        int cnt = 0;
        while (curNode)
        {
            curNode = curNode->next;
            cnt++;
        }

        return cnt;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL)
            return NULL;

        // reverse first k nodes
        int cnt = 1;
        ListNode *cur = head;
        ListNode *prev = NULL;
        ListNode *temp = NULL;
        while (cur != NULL && cnt <= k)
        {
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
            cnt++;
        }

        // reverse next k nodes (if k or more nodes left)
        if (temp != NULL && countNodes(temp) >= k)
            head->next = reverseKGroup(temp, k);
        else
            head->next = temp;

        // prev points to last node (new head)
        return prev;
    }
};
