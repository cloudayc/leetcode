//
//  PlusOne.cpp
//  LTcode
//
//  Created by wyq on 14/11/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a non-negative number represented as an array of digits, plus one to the number.
 
 The digits are stored such that the most significant digit is at the head of the list.
 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void calc()
    {
        vector<int> v;
        v.push_back(9);
        for (int i = 0; i < 20; ++i)
        {
            v.push_back(9);
        }
//        this->print(v);
        this->plusOne(v);
    }
    
    void print(vector<int> v)
    {
        for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        {
            cout << *iter;
        }
        cout << endl;
    }
    
    vector<int> plusOne(vector<int> &digits) {
        int extra = 1;
        for (vector<int>::reverse_iterator iter = digits.rbegin(); iter != digits.rend(); ++iter)
        {
            int addition = *iter + extra;
            *iter = addition % 10;
            extra = addition / 10;
        }
        if (extra > 0)
        {
            digits.insert(digits.begin(), 1);
        }
//        this->print(digits);
        
        return digits;
    }
};
