// https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest
{
public:
    int kth;
    priority_queue<int, vector<int>, greater<int>> minheap;

    KthLargest(int k, vector<int> &nums)
    {
        kth = k;
        int i = 0, n = nums.size();

        // maintain minheap of size k
        // after k insert only if larger than minimum
        for (; i < n; i++)
        {
            if (minheap.size() < k)
                minheap.push(nums[i]);
            else if (nums[i] > minheap.top())
            {
                minheap.pop();
                minheap.push(nums[i]);
            }
        }
    }

    int add(int val)
    {
        // if size less than k insert
        if (minheap.size() < kth)
            minheap.push(val);

        // after k insert if larger than minimum
        else if (minheap.top() < val)
        {
            minheap.pop();
            minheap.push(val);
        }

        // kth largest
        return minheap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
