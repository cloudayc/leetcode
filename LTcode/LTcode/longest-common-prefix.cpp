//
//  longest-common-prefix.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Write a function to find the longest common prefix string amongst an array of strings.
 
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void calc()
    {
        while (true)
        {
            vector<string> v;
            v.push_back("");
            for (int i = 0; i < 1; ++i) {
                string s;
                cin >> s;
                v.push_back(s);
            }
            cout << this->longestCommonPrefix(v) << endl;
        }
        
    }
    
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";
        string prefix = strs.at(0);
        if (prefix.empty())
            return "";
        size_t commonLen = prefix.length();
        for (vector<string>::iterator iter = strs.begin() + 1; iter != strs.end(); ++iter)
        {
            if ((*iter).empty())
                return "";
            commonLen = (*iter).length() < commonLen ? (*iter).length() : commonLen;
            for (int i = 0; i < commonLen; ++i)
            {
                if (prefix[i] != (*iter)[i])
                {
                    commonLen = i;
                    break;
                }
            }
        }
        
        return prefix.substr(0, commonLen);
    }
};