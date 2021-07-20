// https://leetcode.com/problems/minimum-window-substring/

class Solution
{
public:
    // compare frequency maps
    bool compareFreqMaps(int arr1[], int arr2[])
    {
        for (int i = 0; i < 128; i++)
            if (arr1[i] < arr2[i]) // more or equal frequencies are allowed
                return false;

        return true;
    }

    // O(N)
    string minWindow(string s, string t)
    {
        // lowercase and uppercase chars
        int pattern_freq_map[128] = {0};
        int window_freq_map[128] = {0};
        int n = s.size();
        int window_start_index = 0, window_end_index = n - 1, cur_window_size = INT_MAX;

        // frequency map to be checked with window
        for (auto x : t)
            pattern_freq_map[x]++;

        int i = 0, j = 0;
        for (j = 0; j < n; j++)
        {
            // add char in window
            window_freq_map[s[j]]++;

            // while freq maps match and window size >= 1
            while (compareFreqMaps(window_freq_map, pattern_freq_map) && (i <= j))
            {
                // if window size less than last window size, update window params
                if ((j - i + 1) < cur_window_size)
                {
                    window_start_index = i;
                    window_end_index = j;
                    cur_window_size = j - i + 1;
                }

                // contract window from left
                window_freq_map[s[i]]--;
                i++;
            }
        }

        // form final solution string
        string ans = "";
        for (window_start_index; (cur_window_size != INT_MAX) && (window_start_index <= window_end_index); window_start_index++)
            ans += s[window_start_index];

        return ans;
    }
};