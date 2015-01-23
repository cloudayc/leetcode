//
//  Regular-Expression-Matching.cpp
//  LTcode
//
//  Created by wyq on 15/1/23.
//  Copyright (c) 2015年 cloudayc. All rights reserved.
//

#include "commonHeader.h"
/* Description:
 
 Implement regular expression matching with support for '.' and '*'.
 
 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.
 
 The matching should cover the entire input string (not partial).
 
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 
 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true
 
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
using namespace std;
class Solution {
public:
    
    void calc()
    {
        while (1)
        {
            string s;
            cin >> s;
            cout << s.length();
            char *p = new char[s.length() + 1];
            strcpy(p, s.c_str());
            p[s.length()] = 0;
            //            const char *p = s.c_str();
            while(p)
            {
                printf("%c_", *p++);
                //                cout << *p++ << '_';
            }
            return;
            vector<Node *> n = this->structureExpression(p);
            for (vector<Node *>::iterator iter = n.begin(); iter != n.end(); ++iter)
            {
                (*iter)->log();
            }
        }
    }
    
    enum nodeType
    {
        constant,
        dynamic
    };
    struct Node
    {
        nodeType type;
        int start;
        int end;
        bool matched;
        Node(nodeType t = constant, int s = 0, int e = 0, int m = false) : type(t), start(s), end(e), matched(m){};
        void log()
        {
            cout << (type == constant ?  "constant" : "dynamic") << '\t' << start << '\t' << end << '\n';
        };
    };
    
    vector<Node *> structureExpression(const char *p)
    {
        vector<Node *> v;
        int start = -1;
        int current = 0;
        while (p != NULL) {
            if (start == -1)
                start = current;
            if (*p == '*')
            {
                nodeType t = (current - 1 == start) ? dynamic : constant;
                Node *node = new Node(t, current - 1, start);
                v.push_back(node);
                start = -1;
            }
            current++;
            p++;
        }
        if (start != -1)
        {
            v.push_back(new Node(constant, start, current - 1));
        }
        return v;
    }
    
    bool isMatch(const char *s, const char *p) {
        return false;
    }
};