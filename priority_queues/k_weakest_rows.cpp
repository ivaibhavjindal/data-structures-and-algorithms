// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

// structure for heap
struct row
{
    int index;
    int soldiers;
};

// custom comparator (max soldiers/index)
class Compare
{
public:
    bool operator()(row i, row j)
    {
        if (i.soldiers == j.soldiers)
            return i.index < j.index;

        return i.soldiers < j.soldiers;
    }
};

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<row, vector<row>, Compare> maxheap;

        int m = mat.size();
        int n = mat[0].size();

        // if cur row is weaker than strongest row in heap
        // pop strongest and push cur row
        for (int i = 0; i < m; i++)
        {
            row cur = {i, 0};

            for (int j = 0; (j < n) && (mat[i][j] == 1); j++)
                cur.soldiers++;

            if (maxheap.size() < k)
                maxheap.push(cur);
            else if (maxheap.top().soldiers > cur.soldiers)
            {
                maxheap.pop();
                maxheap.push(cur);
            }
        }

        // stronger to weaker order
        vector<int> ans;
        while (!maxheap.empty())
        {
            ans.push_back(maxheap.top().index);
            maxheap.pop();
        }

        // in weaker to stronger order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};