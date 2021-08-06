// https://leetcode.com/problems/sliding-window-maximum/

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> dq(k);
        vector<int> ans;

        // first k elements
        for (int i = 0; i < k; i++)
        {
            // pop elements from back which are smaller
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }

        for (int i = k; i < n; i++)
        {
            // max element in current window
            ans.push_back(nums[dq.front()]);

            // pop elements from front which are out of window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // pop elements from back which are smaller
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        return ans;
    }
};
