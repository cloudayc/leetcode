//
//  RemoveElement.cpp
//  LTcode
//
//  Created by wyq on 14/11/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given an array and a value, remove all instances of that value in place and return the new length.
 
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 
 */

class Solution {
public:
    void calc()
    {
        
    }
    
    int removeElement(int A[], int n, int elem) {
        int nLen = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] != elem)
            {
                A[nLen++] = A[i];
            }
        }
        return nLen;
    }
};