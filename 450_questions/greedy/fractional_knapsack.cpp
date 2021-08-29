// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    static bool compare(pair<double, Item> p1, pair<double, Item> p2)
    {
        // non increasing order
        return p1.first > p2.first;
    }

    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, Item>> vp;
        for (int i = 0; i < n; i++)
            vp.push_back({(double)arr[i].value / (double)arr[i].weight, arr[i]});

        sort(vp.begin(), vp.end(), compare);

        double ans = 0;
        for (auto x : vp)
        {
            if (W > x.second.weight)
            {
                W -= x.second.weight;
                ans += x.second.value;
            }
            else
            {
                ans += ((double)W * x.first);
                break;
            }
        }

        return ans;
    }
};