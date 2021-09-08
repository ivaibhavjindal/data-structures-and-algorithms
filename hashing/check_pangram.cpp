// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        int freq[26] = {0};

        for (char c : sentence)
            freq[c - 'a']++;

        for (int i = 0; i < 26; i++)
            if (freq[i] == 0)
                return false;

        return true;
    }
};