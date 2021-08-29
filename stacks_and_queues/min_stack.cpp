// https://leetcode.com/problems/min-stack/

class MinStack
{
public:
    /** initialize your data structure here. */
    vector<pair<int, int>> st;
    MinStack()
    {
    }

    void push(int val)
    {
        if (st.empty())
            st.push_back({val, val});
        else
            st.push_back({val, min(val, this->getMin())});
    }

    void pop()
    {
        if (st.empty())
            return;
        st.pop_back();
    }

    int top()
    {
        return st[st.size() - 1].first;
    }

    int getMin()
    {
        return st[st.size() - 1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */