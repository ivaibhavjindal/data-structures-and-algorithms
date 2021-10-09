// https://leetcode.com/problems/merge-k-sorted-lists/

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

class Compare {
public:
    bool operator()(ListNode* l1, ListNode *l2) {
        return l1->val > l2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> minheap;
        
        for(auto node: lists) {
            if(node != NULL)
                minheap.push(node);
        }
        
        ListNode *head = NULL, *temp;
        
        while(!minheap.empty()) {
            ListNode *x = minheap.top();
            minheap.pop();
                        
            if(head == NULL) {
                head = new ListNode(x->val);
                temp = head;
            } else {
                ListNode *newNode = new ListNode(x->val);
                temp -> next = newNode;
                temp = newNode;
            }
            
            
            if(x->next != NULL)
                minheap.push(x->next);
        }
        
        return head;
    }
};