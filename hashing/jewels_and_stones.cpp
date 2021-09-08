// https://leetcode.com/problems/jewels-and-stones/

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int ans = 0;
        unordered_set<char> st;

        for (auto ch : jewels)
            st.insert(ch);

        for (auto ch : stones)
            if (st.find(ch) != st.end())
                ans++;

        return ans;
    }
};