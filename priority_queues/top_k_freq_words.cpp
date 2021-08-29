// https://leetcode.com/problems/top-k-frequent-words/

// custom comparator for minheap
class Compare
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        if (a.second == b.second)
            // reverse lexicographic
            return a.first < b.first;

        // freq
        return a.second > b.second;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        // frequency map
        map<string, int> mp;
        for (auto word : words)
            mp[word]++;

        // custom min heap (key = frequency (reverse lexicographic for same freq))
        priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> minheap;

        // if frequency of word greater than minimum freq of word in heap pop and push
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

        vector<string> ans;
        while (!minheap.empty())
        {
            ans.push_back(minheap.top().first);
            minheap.pop();
        }

        // print in non increasing freq order (lexicographic for same)
        reverse(ans.begin(), ans.end());

        return ans;
    }
};