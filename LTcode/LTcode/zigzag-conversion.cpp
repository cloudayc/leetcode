//
//  zigzag-conversion.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 
 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will takePAHNAYLIIRGYIR a string and make this conversion given a number of rows:
 
 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 
 */

#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void calc()
    {
        cout << this->convert("PAYPALISHIRING", 0) << endl;
    }
    
    string convert(string s, int nRows) {
        if (s.length() == 0)
            return "";
        if (nRows <= 1)
            return s;
        char *str = new char[s.length() + 1];
        memset(str, 0, s.length() + 1);
        
        int zigzagLen = nRows * 2 - 2;
        
        size_t zigzagCnt = s.length() / zigzagLen + (s.length() % zigzagLen ? 1 : 0);
        
        int index = 0;
        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < zigzagCnt; ++j)
            {
                int pos = zigzagLen * j + i;
                if (pos >= s.length())
                    continue;
                str[index++] = s[pos];
                
                if (i > 0 && i < nRows - 1)
                {
                    int pos2 = zigzagLen * j + zigzagLen - i;
                    if (pos2 < s.length())
                        str[index++] = s[pos2];
                }
            }
        }
        string re = string(str);
        delete [] str;
        
        return re;
    }
};