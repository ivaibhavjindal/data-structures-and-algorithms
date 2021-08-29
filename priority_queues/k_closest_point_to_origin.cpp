// https://leetcode.com/problems/find-k-closest-elements/

// integer node
struct node
{
    int pos;
    int dist;
};

// custom comparator max heap (key = distance)
class Compare
{
public:
    bool operator()(node a, node b)
    {
        return a.dist < b.dist;
    }
};

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<node, vector<node>, Compare> maxheap;
        int n = arr.size();

        // maintain max heap and if any point has smaller distance
        // than top, pop it and push new node on heap
        for (int i = 0; i < n; i++)
        {
            node cur;
            cur.pos = i;
            cur.dist = abs(x - arr[i]);

            if (maxheap.size() < k)
                maxheap.push(cur);
            else if (maxheap.top().dist > cur.dist)
            {
                maxheap.pop();
                maxheap.push(cur);
            }
        }

        // pop elements from heap
        vector<int> ans;
        while (!maxheap.empty())
        {
            ans.push_back(arr[maxheap.top().pos]);
            maxheap.pop();
        }

        // sort in ascending order
        sort(ans.begin(), ans.end());
        return ans;
    }
};
