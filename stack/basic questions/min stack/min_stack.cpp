#include <stack>
#include <iostream>
using namespace std;

class MinStack {
public:
    stack<int> s;
    int minimum;

    MinStack() 
    {
        while (!s.empty()) s.pop(); // Ensure stack is empty initially
    }
    
    void push(int currentVal) 
    {
        if (s.empty()) 
        {
            minimum = currentVal;
            s.push(currentVal);
        } 
        else 
        {
            if (currentVal >= minimum) 
            {
                s.push(currentVal);
            } 
            else 
            {
                // Push modified value to keep track of the minimum
                s.push(2 * currentVal - minimum);
                minimum = currentVal;
            }
        }
    }
    
    void pop() 
    {
        if (s.empty()) return;

        int topVal = s.top();
        s.pop();

        if (topVal < minimum) 
        {
            minimum = 2 * minimum - topVal; // Restore previous minimum
        }
    }
    
    int top() 
    {
        if (s.empty()) return -1; // Return an invalid value or throw an exception

        int topVal = s.top();
        if (topVal < minimum) 
        {
            return minimum; // Return the current minimum if topVal is modified
        } 
        else 
        {
            return topVal;
        }
    }
    
    int getMin() 
    {
        if (s.empty()) return -1; // Return an invalid value or throw an exception
        return minimum;
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

int main() {
    MinStack* obj = new MinStack();
    obj->push(5);
    obj->push(3);
    obj->push(7);
    cout << "Top element: " << obj->top() << endl; // Output: 7
    cout << "Minimum element: " << obj->getMin() << endl; // Output: 3
    obj->pop();
    cout << "Top element after pop: " << obj->top() << endl; // Output: 3
    cout << "Minimum element after pop: " << obj->getMin() << endl; // Output: 3
    obj->pop();
    cout << "Top element after another pop: " << obj->top() << endl; // Output: 5
    cout << "Minimum element after another pop: " << obj->getMin() << endl; // Output: 5
    return 0;
}
