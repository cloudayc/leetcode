//
//  palindrome-number.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Determine whether an integer is a palindrome. Do this without extra space.
 
 click to show spoilers.
 https://oj.leetcode.com/problems/palindrome-number/#
 
 */

#include <stdio.h>

class Solution {
public:
    void calc()
    {
        while (true)
        {
            int x;
            scanf("%d", &x);
            printf("%d", this->isPalindrome(x));
        }
    }
    
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int t = 1e9;
        while (t > x)
        {
            t /= 10;
        }
        
        while (x > 0)
        {
            if (x / t != x % 10)
                return false;
            x %= t;
            x /= 10;
            t /= 100;
        }
        return true;
    }
};

