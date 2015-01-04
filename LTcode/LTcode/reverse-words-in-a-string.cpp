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
    void calc()
    {
        while (true)
        {
            string str;
            getline(cin, str);
            this->reverseWords(str);
            cout << str << endl;
        }
    }
    
    void removeExtraSpaces(string &s)
    {
        int len = 0;
        bool needSpace = false;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] != ' ')
            {
                s[len++] = s[i];
                needSpace = true;
            }
            else if (needSpace)
            {
                s[len++] = s[i];
                needSpace = false;
            }
        }
        if (len - 1 >= 0 && s[len - 1] == ' ')
            --len;
        s.resize(len);
    }
    
    void reverseString(string &s, int left, int right)
    {
        while (left <= right)
        {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            left++;
            right--;
        }
        
    }
    
    void reverseWords(string &s) {
        if (s.length() == 0)
            return;
        this->removeExtraSpaces(s);
        
        this->reverseString(s, 0, s.size() - 1);
        
        int left = -1;
        int right = 0;
        int flag = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (flag == 0 && s[i] != ' ')
            {
                flag = 1;
                if (left == -1)
                    left = i;
            }
            else if (flag == 1 && s[i] == ' ')
            {
                flag = 0;
                right = i - 1;
                this->reverseString(s, left, right);
                left = -1;
            }
        }
        if (flag == 1)
            this->reverseString(s, left, s.size() - 1);
    }
};