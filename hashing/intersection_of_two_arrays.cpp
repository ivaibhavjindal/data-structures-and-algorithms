// https://leetcode.com/problems/intersection-of-two-arrays/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        map<int, int> mp;
        for (auto num : nums1)
            mp[num] = 1;

        vector<int> ans;
        for (auto num : nums2)
        {
            if (mp.find(num) != mp.end() && mp[num] != 0)
            {
                ans.push_back(num);
                mp[num] = 0;
            }
        }

        return ans;
    }
};