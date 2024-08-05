
class MinStack 
{
    stack<long long> st;
    long long mini;
public:
    /** initialize your data structure here. */
    MinStack() {
        // Ensuring the stack is empty and initializing mini
        while (!st.empty()) st.pop();
        mini = LLONG_MAX; // Using LLONG_MAX for consistency with long long type
    }

    void push(int value) {
        long long val = static_cast<long long>(value);
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val < mini) {
                // Pushing the encoded value
                st.push(2 * val - mini);
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long el = st.top();
        st.pop();

        if (el < mini) {
            // Updating mini to the previous minimum value
            mini = 2 * mini - el;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long el = st.top();
        if (el < mini) return static_cast<int>(mini);
        return static_cast<int>(el);
    }

    int getMin() {
        return static_cast<int>(mini);
    }
};
