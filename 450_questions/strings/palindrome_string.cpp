// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

class Solution
{
public:
    int isPlaindrome(string S)
    {
        int i = 0, j = S.size() - 1;
        while (i < j)
        {
            if (S[i] != S[j])
                return 0;

            i++;
            j--;
        }

        return 1;
    }
};
