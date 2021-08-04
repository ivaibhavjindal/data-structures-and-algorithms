// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
using namespace std;

int stairs(int n, int cur_stair)
{
    if (n == cur_stair)
        return 1;
    else if (cur_stair > n)
        return 0;

    return stairs(n, cur_stair + 1) + stairs(n, cur_stair + 2);
}

int climbStairs(int n)
{
    return stairs(n, 0);
}

int main()
{
    int n;
    cin >> n;
    cout << climbStairs(40) << endl;
}