// https://practice.geeksforgeeks.org/problems/count-squares3649/1

class Solution
{
public:
    int countSquares(int N)
    {
        int k = sqrt(N);
        if (k * k == N)
            return k - 1;

        return k;
    }
};
