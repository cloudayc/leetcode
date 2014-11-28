//
//  pascals-triangle.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given numRows, generate the first numRows of Pascal's triangle.
 
 For example, given numRows = 5,
 Return
 
 [
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
 ]
 
 */

#include <iostream>
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
            this->generate(x);
        }
    }
    
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vv;
        if (numRows == 0)
            return vv;
        vector<int> v;
        v.push_back(1);
        vv.push_back(v);
        for (int i = 1; i < numRows; ++i) {
            vector<int> prev = vv[i - 1];
            vector<int> iv;
            for (int j = 0; j <= i; ++j)
            {
                int a = (j - 1) >= 0 ? prev[j - 1] : 0;
                int b = j < i ? prev[j] : 0;
             
//                cout << a + b << ' ';
                
                iv.push_back(a + b);
            }
            vv.push_back(iv);
//            cout << endl;
        }
        return vv;
    }
};