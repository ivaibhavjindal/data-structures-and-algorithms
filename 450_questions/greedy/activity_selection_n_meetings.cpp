// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

class Solution
{
public:
    static bool comp(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second < p2.second;
    }

    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
            vp.push_back({start[i], end[i]});

        sort(vp.begin(), vp.end(), comp);

        int ans = 1, last = vp[0].second;
        for (int i = 1; i < n; i++)
        {
            if (vp[i].first > last)
            {
                last = vp[i].second;
                ans++;
            }
        }

        return ans;
    }
};
