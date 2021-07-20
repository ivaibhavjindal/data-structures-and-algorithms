// https://leetcode.com/problems/3sum/

class Solution
{
public:
    // O(N^2)
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<tuple<int, int, int>> s;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            int j = i + 1;
            int k = n - 1;
            int target_sum = -nums[i];

            while (j < k)
            {
                if (nums[j] + nums[k] == target_sum)
                {
                    s.insert(make_tuple(nums[i], nums[j], nums[k]));
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > target_sum)
                    k--;
                else
                    j++;
            }
        }

        vector<vector<int>> result;
        for (auto triplet : s)
        {
            vector<int> v;
            v.push_back(get<0>(triplet));
            v.push_back(get<1>(triplet));
            v.push_back(get<2>(triplet));

            result.push_back(v);
        }

        return result;
    }
};