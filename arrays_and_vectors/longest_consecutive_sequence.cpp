// https://leetcode.com/problems/longest-consecutive-sequence/
// another approach can be using sorting (O(N*log(N)))

class Solution
{
public:
    // O(N)
    int longestConsecutive(vector<int> &nums)
    {
        int max_len = 0;
        unordered_set<int> s;

        for (auto num : nums)
            s.insert(num);

        for (auto num : nums)
        {
            // start of chain
            if (s.find(num - 1) == s.end())
            {
                // length of cur chain
                int cur_len = 1, x = num + 1;
                while (s.find(x) != s.end())
                {
                    cur_len++;
                    x++;
                }

                max_len = max(cur_len, max_len);
            }
        }

        return max_len;
    }
};