// https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1

int minFlips(string S)
{
    int s0 = 0, s1 = 0, n = S.size();

    for (int i = 0; i < n; i++)
    {
        if (i & 1)
        {
            if (S[i] == '1')
                s1++;
            else
                s0++;
        }
        else
        {
            if (S[i] == '0')
                s1++;
            else
                s0++;
        }
    }

    return min((int)s0, (int)s1);
}