//
//  AddBinary.cpp
//  LTcode
//
//  Created by wyq on 14/11/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given two binary strings, return their sum (also a binary string).
 
 For example,
 a = "11"
 b = "1"
 Return "100".
 
 */

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void calc()
    {
        cout << this->addBinary("0", "0") << endl;
    }
    
    string addBinary(string a, string b) {
        try {
            string &addend = a.length() >= b.length() ? a : b;
            string &beAddend = a.length() >= b.length() ? b : a;
            
            int extra = 0;
            for (int i = addend.length() - 1, j = beAddend.length() - 1; i >= 0; --i, --j)
            {
                int b1 = addend.at(i) == '1' ? 1 : 0;
                int b2 = 0;
                if (j >= 0)
                {
                    b2 = beAddend.at(j) == '1' ? 1 : 0;
                }
                addend[i] = (b1 ^ b2 ^ extra) == 1 ? '1' : '0';
                extra = (b1 + b2 + extra) >= 2 ? 1 : 0;
            }
           return (extra > 0 ? "1" : "") + addend;
        } catch (exception e) {
            cout << e.what() << endl;
        }
        return a;
    }
};