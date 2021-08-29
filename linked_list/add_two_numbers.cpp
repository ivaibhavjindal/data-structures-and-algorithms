// https://leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *root = NULL, *froot = NULL;
        int carry = 0;
        while (l1 && l2)
        {
            ListNode *n = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;

            if (root == NULL)
            {
                root = n;
                froot = n;
            }
            else
            {
                root->next = n;
                root = n;
            }

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1)
        {
            ListNode *n = new ListNode((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;

            if (root == NULL)
            {
                root = n;
                froot = n;
            }
            else
            {
                root->next = n;
                root = n;
            }

            l1 = l1->next;
        }

        while (l2)
        {
            ListNode *n = new ListNode((l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;

            if (root == NULL)
            {
                root = n;
                froot = n;
            }
            else
            {
                root->next = n;
                root = n;
            }

            l2 = l2->next;
        }

        if (carry)
        {
            ListNode *n = new ListNode(carry);
            root->next = n;
            root = n;
        }

        return froot;
    }
};