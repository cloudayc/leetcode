//
//  valid-palindrome.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 
 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.
 
 Note:
 Have you consider that the string might be empty? This is a good question to ask during an interview.
 
 For the purpose of this problem, we define empty string as valid palindrome.
 
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
            string x;
            getline(cin, x);
            cout << this->isPalindrome(x) << endl;
        }
    }
    
    bool alphanumeric(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    
    char lowerCase(char c)
    {
        if (c >= 'A' && c <= 'Z')
        {
            return c + 32;
        }
        return c;
    }
    
    bool isPalindrome(string s) {
        if (s.length() == 0)
            return true;
        
        int h = 0;
        int t = s.length() - 1;
        while (h < t)
        {
            if (!this->alphanumeric(s[h]))
            {
                h++;
                continue;
            }
            if (!this->alphanumeric(s[t]))
            {
                t--;
                continue;
            }
            if (this->lowerCase(s[h]) != this->lowerCase(s[t]))
                return false;
            h++;
            t--;
        }
        return true;
    }
};