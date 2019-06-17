#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        is_c_first = true;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(is_c_first)
        {
            _c1.push(x);
            while(_c2.size())
            {
                _c1.push(_c2.front());
                _c2.pop();
            }
            is_c_first = false;
        }
        else
        {
            _c2.push(x);
            while(_c1.size())
            {
                _c2.push(_c1.front());
                _c1.pop();
            }
            is_c_first = true;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front;
        if(is_c_first)
        {
            front = _c2.front();
            _c2.pop();
        }
        else
        {
            front = _c1.front();
            _c1.pop();
        }
        return front;
    }
    
    /** Get the top element. */
    int top() {
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _c1.empty() && _c2.empty();
    }

private:
    bool is_c_first;
    queue<int> _c1;
    queue<int> _c2;

};