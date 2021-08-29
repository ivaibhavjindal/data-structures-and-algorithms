// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        priority_queue<int> maxheap;

        for (auto x : nums)
            maxheap.push(x);

        int elem1 = maxheap.top() - 1;
        maxheap.pop();
        int elem2 = maxheap.top() - 1;

        return elem1 * elem2;
    }
};