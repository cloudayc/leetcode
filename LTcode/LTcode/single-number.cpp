//
//  single-number.cpp
//  LTcode
//
//  Created by wyq on 14/12/9.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given an array of integers, every element appears twice except for one. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 
 */

class Solution {
public:
    int singleNumber(int A[], int n) {
        int re = 0;
        for (int i = 0; i < n; ++i)
            re ^= A[i];
        return re;
    }
};