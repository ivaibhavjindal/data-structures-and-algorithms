// https://leetcode.com/problems/relative-ranks/

// structure for heap
struct athlete
{
    int index;
    int score;
};

// custom comparator (key=score)
class Compare
{
public:
    bool operator()(athlete a, athlete b)
    {
        return a.score < b.score;
    }
};

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        int n = score.size();
        int rank = 1;

        vector<string> ans(n);
        priority_queue<athlete, vector<athlete>, Compare> maxheap;

        // building max heap
        for (int i = 0; i < n; i++)
        {
            athlete cur = {i, score[i]};
            maxheap.push(cur);
        }

        // maintaing ranks
        while (!maxheap.empty())
        {
            athlete ath = maxheap.top();
            maxheap.pop();

            if (rank == 1)
                ans[ath.index] = "Gold Medal";
            else if (rank == 2)
                ans[ath.index] = "Silver Medal";
            else if (rank == 3)
                ans[ath.index] = "Bronze Medal";
            else
                ans[ath.index] = to_string(rank);

            rank++;
        }

        return ans;
    }
};