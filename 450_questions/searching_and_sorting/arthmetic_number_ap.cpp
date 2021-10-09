// https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1

class Solution
{
public:
    int inSequence(int A, int B, int C)
    {
        if (C == 0 || A == B)
            return A == B;

        if (((C > 0) && (B > A)) || ((C < 0) && (B < A)))
        {
            double k = (double)(B - A) / (double)C;
            return k == ceil(k);
        }

        return 0;
    }
};
