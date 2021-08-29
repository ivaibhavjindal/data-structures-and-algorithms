// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder
{
public:
    /** initialize your data structure here. */
    priority_queue<int> leftheap;                             // maxheap
    priority_queue<int, vector<int>, greater<int>> rightheap; // minheap

    MedianFinder() {}

    void addNum(int num)
    {
        if (leftheap.empty() && rightheap.empty())
            leftheap.push(num);

        else if (leftheap.size() < rightheap.size())
        {
            double median = this->findMedian();

            if (num < median)
                leftheap.push(num);
            else
            {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(num);
            }
        }

        else if (leftheap.size() > rightheap.size())
        {
            double median = this->findMedian();

            if (num > median)
                rightheap.push(num);
            else
            {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(num);
            }
        }

        else
        {
            double median = this->findMedian();
            if (num < median)
                leftheap.push(num);
            else
                rightheap.push(num);
        }
    }

    double findMedian()
    {
        if (rightheap.size() == leftheap.size())
            return ((double)rightheap.top() + (double)leftheap.top()) / 2;
        else if (rightheap.size() > leftheap.size())
            return rightheap.top();
        else
            return leftheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */