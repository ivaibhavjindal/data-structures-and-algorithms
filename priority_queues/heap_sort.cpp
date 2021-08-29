// https://leetcode.com/problems/sort-an-array/

class Compare {
    public:
    bool operator()(int a, int b) {
        // min heap
        return a > b;

        // max heap
        return a < b;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // priority_queue <int, vector<int>, greater<int>> minheap;
        // priority_queue<int> maxheap;

        vector<int> ans;
        priority_queue<int, vector<int>, Compare> heap;
        for(auto x: nums)
            heap.push(x);
        
        while(!heap.empty()) {
            ans.push_back(heap.top());
            heap.pop();
        }

        return ans;
    }
};