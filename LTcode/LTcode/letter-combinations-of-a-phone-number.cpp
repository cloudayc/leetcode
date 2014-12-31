//
//  letter-combinations-of-a-phone-number.cpp
//  LTcode
//
//  Created by wyq on 14/12/9.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a digit string, return all possible letter combinations that the number could represent.
 
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 
 http://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png
 
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.
 
 */

#include <string>
#include <vector>
#include "commonHeader.h"
using namespace std;

class Solution {
public:
    void calc()
    {
        while (true)
        {
            string s;
            cin >> s;
            vector<string> t = this->letterCombinations(s);
            for (vector<string>::iterator iter = t.begin(); iter != t.end(); ++iter)
            {
                cout << *iter << ' ' << ends;
            }
        }
    }
    string getLettersByDigit(char digit)
    {
        switch (digit) {
            case '1':
                return "";   break;
            case '2':
                return "abc";   break;
            case '3':
                return "def";   break;
            case '4':
                return "ghi";   break;
            case '5':
                return "jkl";   break;
            case '6':
                return "mno";   break;
            case '7':
                return "pqrs";   break;
            case '8':
                return "tuv";   break;
            case '9':
                return "wxyz";   break;
            default:
                return "";      break;
        }
    }
    // from end to begin
    vector<int> calcRepeatCount(string digits, int *totalCount)
    {
        vector<int> iv;
        int repTimes = 1;
        const char *c_digits = digits.c_str();
        for (int i = (int)digits.length() - 1; i >= 0; --i)
        {
            iv.push_back(repTimes);
            repTimes *= this->getLettersByDigit(c_digits[i]).length();
        }
        *totalCount = repTimes;
        
        return iv;
    }
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
        {
            vector<string> re;
            re.push_back("");
            return re;
        }
        
        int totalCount = 0;
        vector<int> repVector = this->calcRepeatCount(digits, &totalCount);
        
        string t;
        vector<string> vs(totalCount, t);
        
        const char *c_digits = digits.c_str();
        for (size_t i = 0; i < digits.length(); ++i)
        {
            string digitStr = this->getLettersByDigit(c_digits[i]);
            
            int repCount = repVector.back();
            repVector.pop_back();
            if (digitStr.length() == 0)
                continue;
            int loopCount = totalCount / (repCount * digitStr.length());
            int index = 0;
            while (loopCount--)
            {
                for (size_t li = 0; li < digitStr.length(); ++li)
                {
                    for (int re = 0; re < repCount; ++re)
                    {
                        vs[index++].push_back(digitStr[li]);
                    }
                }
            }
            
        }
        return vs;
    }
};
