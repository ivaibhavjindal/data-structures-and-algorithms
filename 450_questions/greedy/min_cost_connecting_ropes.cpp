// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

class Solution
{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n)
    {
        long long cost = 0;

        priority_queue<long long, vector<long long>, greater<long long>> minheap;
        for (int i = 0; i < n; i++)
            minheap.push(arr[i]);

        // greedy approach merge smallest two ropes each time
        while (minheap.size() > 1)
        {
            long long elem1 = minheap.top();
            minheap.pop();
            long long elem2 = minheap.top();
            minheap.pop();

            cost += elem1 + elem2;
            minheap.push(elem1 + elem2);
        }

        return cost;
    }
};