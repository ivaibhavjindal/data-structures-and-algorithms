// https://leetcode.com/problems/two-sum/

class Solution
{
public:
    // O(N)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result(2);
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            int pair_num = target - nums[i];
            if (mp.find(pair_num) != mp.end())
            {
                result[0] = i;
                result[1] = mp[pair_num];

                return result;
            }

            mp[nums[i]] = i;
        }

        return result;
    }
};