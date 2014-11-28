//
//  pascals-triangle-ii.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given an index k, return the kth row of the Pascal's triangle.
 
 For example, given k = 3,
 Return [1,3,3,1].
 
 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 1
 1 1
 1 2 1
 1 3 3 1
 */

#include <stdio.h>

#include <vector>
using namespace std;

class Solution {
public:
    void calc()
    {
        while (true)
        {
            int x;
            scanf("%d", &x);
            
            vector<int> t = this->getRow(x);
            for (vector<int>::iterator iter = t.begin(); iter != t.end(); ++iter) {
                printf("%d ", *iter);
            }
            printf("\n");
        }
    }
    
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        v.push_back(1);
        for (int i = 1; i <= rowIndex; ++i)
        {
            int t = 0;
            for (int j = 0; j < i; ++j)
            {
                int tmp = v[j];
                v[j] = v[j] + t;
                t = tmp;
            }
            v.push_back(1);
        }
        return v;
    }
};









