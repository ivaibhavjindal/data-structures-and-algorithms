// https://leetcode.com/problems/find-k-closest-elements/

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<int> maxheap;
        vector<int> nums;
        for (auto num : arr)
            nums.push_back(abs(x - num));

        for (int i = 0; i < n; i++)
        {
            if (maxheap.size() < k)
                maxheap.push(i);
            else if (nums[maxheap.top()] > nums[i])
            {
                maxheap.pop();
                maxheap.push(i);
            }
        }

        // pop elements from heap
        vector<int> ans;
        while (!maxheap.empty())
        {
            ans.push_back(arr[maxheap.top()]);
            maxheap.pop();
        }

        return ans;
    }
};