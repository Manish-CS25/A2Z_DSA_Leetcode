class CustomStack {
public:
    vector<int> st;
    int maxSize = 0;
    CustomStack(int max_size) { maxSize = max_size; }

    void push(int x) {
        if (st.size() < maxSize)
            st.push_back(x);
        else
            return;
    }

    int pop() {
        if (st.empty())
            return -1;
        int t = st.back();
        st.pop_back();
        return t;
    }

    void increment(int k, int val) {
        if (st.size() < k) {
            for (int i = 0; i < st.size(); i++) {
                st[i] += val;
            }
        }

        else {

            for (int i = 0; i < k; i++) {
                st[i] += val;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */