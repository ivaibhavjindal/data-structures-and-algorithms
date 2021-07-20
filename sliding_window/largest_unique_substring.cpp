// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    // O(N)
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int i = 0, j = 0, ans = 0;
        for (j = 0; s[j]; j++)
        {
            // char previously seen and present in cur window
            if (mp.find(s[j]) != mp.end() and mp[s[j]] >= i)
            {
                i = mp[s[j]] + 1; // move start of window to right of duplicate char
                mp[s[j]] = j;     // update element index in window
            }
            else
                mp[s[j]] = j; // add element index if not in window

            // window size = j-i+1
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};