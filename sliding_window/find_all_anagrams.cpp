// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution
{
public:
    bool checkAnagram(vector<int> &arr1, vector<int> &arr2)
    {
        for (int i = 0; i < 26; i++)
            if (arr1[i] != arr2[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {
        int k = p.size();
        int n = s.size();

        if (k > n)
            return {};

        vector<int> freqP(26, 0), freqS(26, 0);
        for (char ch : p)
            freqP[ch - 'a']++;

        for (int i = 0; i <= k - 1; i++)
            freqS[s[i] - 'a']++;

        vector<int> ans;
        if (checkAnagram(freqS, freqP))
            ans.push_back(0);

        for (int i = k; i < n; i++)
        {
            freqS[s[i - k] - 'a']--;
            freqS[s[i] - 'a']++;

            if (checkAnagram(freqS, freqP))
                ans.push_back(i - k + 1);
        }

        return ans;
    }
};