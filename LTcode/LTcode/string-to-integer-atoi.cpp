//
//  string-to-integer-atoi.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Implement atoi to convert a string to an integer.
 
 Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 
 spoilers alert... click to show requirements for atoi.
 https://oj.leetcode.com/problems/string-to-integer-atoi/#
 
 */

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void calc()
    {
        while (true)
        {
            string s;
            getline(cin, s);
            cout << this->atoi(s.c_str()) << endl;
        }
    }
    
    bool checkValid(const char *str)
    {
        while (*str)
        {
            char c = *str;
            if (c < '0' || c > '9')
                if (c != ' ')
                    return false;
            str++;
        }
        return true;
    }
    
    bool checkDigit(char c)
    {
        return c >= '0' && c <= '9';
    }
    
    int atoi(const char *str) {
        if (!str || !*str) return 0;
        
        const char *head = str;
        
        while (*head < '0' || *head > '9') head++;
        
        int sign = 1;
        if (head - 1 >= str)
        {
            if (*(head - 1) == '-')
                sign = -1;
            else if (*(head - 1) == '+' || *(head - 1) == ' ')
                sign = 1;
            else
                return 0;
            
            const char *flt = head - 2;
            while (flt >= str)
            {
                if (*flt != ' ')
                    return 0;
                flt--;
            }
        }
        
        
        int cnt = 0;
        while (this->checkDigit(*head))
        {
            int num = sign * (*head - '0');
            if (cnt >= 214748364)
            {
                if (num > 7 || this->checkDigit(*(head + 1)) || cnt >= 1e9)
                    num = 7;
                return 2147483640 + num;
            }
            if (cnt <= -214748364)
            {
                if (num < -8 || this->checkDigit(*(head + 1)) || cnt <= -1e9)
                    num = -8;
                return -2147483640 + num;
            }
            cnt *= 10;
            cnt += num;
            head++;
        }
        
        return cnt;
    }
};
