// https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1

class Solution
{
public:
    vector<int> kLargest(int arr[], int n, int k)
    {
        priority_queue<int, vector<int>, greater<int>> minheap;

        for (int i = 0; i < n; i++)
        {
            if (minheap.size() < k)
                minheap.push(arr[i]);
            else if (arr[i] > minheap.top())
            {
                minheap.pop();
                minheap.push(arr[i]);
            }
        }

        vector<int> ans;
        while (!minheap.empty())
        {
            ans.push_back(minheap.top());
            minheap.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};