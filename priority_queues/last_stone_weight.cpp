// https://leetcode.com/problems/last-stone-weight/

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> maxheap;

        for (auto stone : stones)
            maxheap.push(stone);

        // pop two heaviest stones
        while (maxheap.size() > 1)
        {
            int y = maxheap.top();
            maxheap.pop();

            int x = maxheap.top();
            maxheap.pop();

            // if both same destroyed
            // else lighter destroyed, heavier updated
            if (x != y)
                maxheap.push(y - x);
        }

        // if non empty
        if (maxheap.size())
            return maxheap.top();
        else
            return 0;
    }
};