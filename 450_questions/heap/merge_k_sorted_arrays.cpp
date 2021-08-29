// https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

struct heapnode
{
    int val;
    int row;
    int col;
};

class Compare
{
public:
    bool operator()(heapnode a, heapnode b)
    {
        return a.val > b.val;
    }
};

class Solution
{
public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<heapnode, vector<heapnode>, Compare> minheap;
        vector<int> ans;

        for (int i = 0; i < K; i++)
        {
            heapnode cur = {arr[i][0], i, 0};
            minheap.push(cur);
        }

        while (!minheap.empty())
        {
            heapnode top = minheap.top();
            minheap.pop();

            ans.push_back(top.val);
            if (top.col < K - 1)
            {
                heapnode newnode = {arr[top.row][top.col + 1], top.row, top.col + 1};
                minheap.push(newnode);
            }
        }

        return ans;
    }
};
