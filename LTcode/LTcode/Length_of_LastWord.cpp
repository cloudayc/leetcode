//
//  Length_of_LastWord.cpp
//  LTcode
//
//  Created by wyq on 14/11/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 
 If the last word does not exist, return 0.
 
 Note: A word is defined as a character sequence consists of non-space characters only.
 
 For example,
 Given s = "Hello World",
 return 5.
 
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void calc()
    {
        string s;
        getline(cin, s);
        printf("%d\n", this->lengthOfLastWord(s.c_str()));
    }
    
    bool isAlpha(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    
    int lengthOfLastWord(const char *s) {
        const char *p = s;
        
        while (*++p != '\0');
        
        p--;
        
        while (p >= s && !this->isAlpha(*p))
        {
            p--;
        }
        
        int cnt = 0;
        while (p >= s && this->isAlpha(*p))
        {
            p--;
            ++cnt;
        }
        
        return cnt;
    }
};