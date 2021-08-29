// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        priority_queue<int> maxheap;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (maxheap.size() < k)
                    maxheap.push(matrix[i][j]);
                else if (maxheap.top() > matrix[i][j])
                {
                    maxheap.pop();
                    maxheap.push(matrix[i][j]);
                }
            }
        }

        return maxheap.top();
    }
};