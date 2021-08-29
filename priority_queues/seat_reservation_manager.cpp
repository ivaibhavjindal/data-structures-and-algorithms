// https://leetcode.com/problems/seat-reservation-manager/

class SeatManager
{
public:
    priority_queue<int, vector<int>, greater<int>> minheap;

    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
            minheap.push(i);
    }

    int reserve()
    {
        if (minheap.empty())
            return -1;

        int seat = minheap.top();
        minheap.pop();

        return seat;
    }

    void unreserve(int seatNumber)
    {
        minheap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */