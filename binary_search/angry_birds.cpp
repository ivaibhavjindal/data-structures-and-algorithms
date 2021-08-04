// place b birds in n nests at maximum
// distance possible and return the distance

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceBirds(vector<int> nests, int n, int b, int sep)
{
    int birds = 1;
    int last_location = nests[0];
    for (int i = 1; i < n; i++)
    {
        if (nests[i] - last_location >= sep)
        {
            birds++;
            last_location = nests[i];

            if (birds == b)
                return true;
        }
    }

    return false;
}

int placeBirds(vector<int> nests, int b)
{
    // sort nests in non - decreasing order for canPlace to work
    sort(nests.begin(), nests.end());

    // search space = (0, difference b/w farthest nests)
    int n = nests.size();
    int s = 0, e = nests[n - 1] - nests[0], ans = 0;
    while (s <= e)
    {
        int m = (s + e) / 2;
        bool canPlace = canPlaceBirds(nests, n, b, m);
        if (canPlace)
        {
            ans = m;
            s = m + 1;
        }
        else
            e = m - 1;
    }

    return ans;
}

int main()
{
    int birds = 3;
    vector<int> nests = {1, 2, 4, 8, 9};
    cout << placeBirds(nests, birds) << endl;
}