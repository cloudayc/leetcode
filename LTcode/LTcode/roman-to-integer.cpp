//
//  roman-to-integer.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a roman numeral, convert it to an integer.
 
 Input is guaranteed to be within the range from 1 to 3999.
 
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void calc()
    {
        while (true)
        {
            string x;
            cin >> x;
            cout << this->romanToInt(x) << endl;
        }
    }
    
    int value(char c)
    {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return 0;
    }
    
    int romanToInt(string s) {
        int re = 0;
        for (int i = 0; i < s.length(); ++i) {
            int v = this->value(s[i]);
            if (i + 1 < s.length() && v < this->value(s[i + 1]))
            {
                v = this->value(s[i + 1]) - v;
                ++i;
            }
            re += v;
        }
        return re;
    }
};