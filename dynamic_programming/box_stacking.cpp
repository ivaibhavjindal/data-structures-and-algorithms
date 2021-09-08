// https: //practice.geeksforgeeks.org/problems/box-stacking/1

class Solution
{
public:
    int bottomUp(vector<vector<int>> &arr, int n)
    {
        sort(arr.begin(), arr.end());
    }

    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    int maxHeight(int height[], int width[], int length[], int n)
    {
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            vector<int> hwl = {height[i], width[i], length[i]};
            arr.push_back(hwl);
        }
    }
};