//
//  MinStack.cpp
//  LTcode
//
//  Created by wyq on 14/11/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 
 push(x) -- Push element x onto stack.
 pop() -- Removes the element on top of the stack.
 top() -- Get the top element.
 getMin() -- Retrieve the minimum element in the stack.
 
 */

#include <stack>

class MinStack {
private:
    std::stack<int> s;
    std::stack<int> m;
    
public:
    void calc()
    {
        for (int i = 2; i < 5; ++i) {
            this->push(i * 2);
        }
        this->push(1);
        
//        int x = this->getMin();
    }
    
    void push(int x) {
        s.push(x);
        if (m.empty() || x <= m.top())
        {
            m.push(x);
        }
    }
    
    void pop() {
        if (s.empty())
            return;
        
        if (s.top() == m.top())
        {
            m.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
};
