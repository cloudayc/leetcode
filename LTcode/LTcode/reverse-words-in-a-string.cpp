//
//  reverse-words-in-a-string.cpp
//  LTcode
//
//  Created by wyq on 14/12/31.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//


/* Description:
 
 Given an input string, reverse the string word by word.
 
 For example,
 Given s = "the sky is blue",
 return "blue is sky the".
 
 click to show clarification.
 
 Clarification:
 What constitutes a word?
 A sequence of non-space characters constitutes a word.
 Could the input string contain leading or trailing spaces?
 Yes. However, your reversed string should not contain leading or trailing spaces.
 How about multiple spaces between two words?
 Reduce them to a single space in the reversed string.
 
 */


#include "commonHeader.h"
using namespace std;

class Solution {
public:
    
    void reverseString(string &s, int left, int right)
    {
        while (left < right)
        {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            left++;
            right--;
        }
        
    }
    void reverseWords(string &s) {
        for (size_t i = 0; i < s.size() / 2; ++i)
        {
            char t = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = t;
        }
        int left = 0;
        int right = 0;
        int flag = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (flag == 0 && s[i] != ' ')
            {
                flag = 1;
                left = i;
            }
            else if (flag == 1 && s[i] == ' ')
            {
                flag = 0;
                right = i - 1;
                this->reverseString(s, left, right);
            }
        }
        if (flag == 1)
            this->reverseString(s, left, right);
    }
};