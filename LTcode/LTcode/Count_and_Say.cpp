//
//  Count_and_Say.cpp
//  LTcode
//
//  Created by wyq on 14/11/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...
 
 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
 
 Note: The sequence of integers will be represented as a string.
 
 */

#include <math.h>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    void calc()
    {
        this->countAndSay(22);
    }
    
    void print(char *p)
    {
        string str(p);
        cout << str << endl;
    }
    
    void writeNumer(char *se, int *index, int num)
    {
        if (num < 10)
        {
            se[(*index)++] = num + '0';
        }
        else
        {
            while (num)
            {
                se[(*index)++] = num % 10 + '0';
                num /= 10;
            }
        }
    }
    
    string countAndSay(int n)
    {
        double capacity = 1.4;
        for (int i = 0; i < n; ++i) {
            capacity *= 1.4;
        }
        capacity += 4;
        
        char *se = new char[(int)capacity];
        char *tmp = new char[(int)capacity];
        memset(se, 0, capacity);
        memset(tmp, 0, capacity);
        
        se[0] = '1';
        
        for (int i = 1; i < n; ++i)
        {
            int tmpIndex = 0;
            
            char curNum = se[0];
            int seCnt = 1;
            for (int j = 1; se[j]; ++j)
            {
                if (se[j] != curNum)
                {
                    this->writeNumer(tmp, &tmpIndex, seCnt);
                    this->writeNumer(tmp, &tmpIndex, curNum - '0');
                    curNum = se[j];
                    seCnt = 1;
                }
                else
                {
                    seCnt++;
                }
            }
            this->writeNumer(tmp, &tmpIndex, seCnt);
            this->writeNumer(tmp, &tmpIndex, curNum - '0');
            
            char *t = se;
            se = tmp;
            tmp = t;
            
            se[tmpIndex] = '\0';
//            this->print(se);
        }
        
        string re(se);
        
        delete [] se;
        delete [] tmp;
        return re;
    }
};