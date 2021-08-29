// https://leetcode.com/problems/maximum-score-from-removing-stones/

class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        priority_queue<int> maxheap;
        maxheap.push(a);
        maxheap.push(b);
        maxheap.push(c);

        int ans = 0;
        while (true)
        {
            int el1 = maxheap.top();
            maxheap.pop();
            int el2 = maxheap.top();
            maxheap.pop();

            if (el1 == 0 || el2 == 0)
                break;

            el1--;
            el2--;

            maxheap.push(el1);
            maxheap.push(el2);
            ans++;
        }

        return ans;
    }
};