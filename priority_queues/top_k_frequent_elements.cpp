// https://leetcode.com/problems/top-k-frequent-elements/

// custom comparator for minheap
class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        // frequency map
        map<int, int> mp;
        for (auto num : nums)
            mp[num]++;

        // custom min heap (key = frequency)
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minheap;

        // if frequency of element greater than minimum freq of element in heap pop and push
        for (auto p : mp)
        {
            if (minheap.size() < k)
                minheap.push(p);
            else if (minheap.top().second < p.second)
            {
                minheap.pop();
                minheap.push(p);
            }
        }

        vector<int> ans;
        while (!minheap.empty())
        {
            ans.push_back(minheap.top().first);
            minheap.pop();
        }

        return ans;
    }
};