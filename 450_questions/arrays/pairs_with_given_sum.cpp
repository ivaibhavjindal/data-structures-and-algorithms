// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        int ans = 0;
        map<int, int> mp;
        
        for(int i = 0; i < n; i++) {
            if(mp.find(k-arr[i]) != mp.end())
                ans += mp[k-arr[i]];
            
            mp[arr[i]]++;
        }
        
        return ans;
    }
};
