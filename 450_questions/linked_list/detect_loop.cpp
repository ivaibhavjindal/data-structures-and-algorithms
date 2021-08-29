// https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1

class Solution
{
public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        Node *slow = head;
        Node *fast = slow;

        do
        {
            if (slow && slow->next)
                slow = slow->next;
            else
                return false;

            if (fast && fast->next && fast->next->next)
                fast = fast->next->next;
            else
                return false;

        } while (fast != slow);

        return true;
    }
};