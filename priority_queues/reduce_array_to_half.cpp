// https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        map<int, int> mp; // frequency map
        for (auto x : arr)
            mp[x]++;

        priority_queue<int> maxheap; // key = frequency
        for (auto p : mp)
            maxheap.push(p.second);

        int n = arr.size() / 2;
        int ans = 0;
        while ((!maxheap.empty()) && (n > 0))
        {
            n -= maxheap.top();
            maxheap.pop();
            ans++;
        }

        return ans;
    }
};