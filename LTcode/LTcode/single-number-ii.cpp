//
//  single-number-ii.cpp
//  LTcode
//
//  Created by wyq on 14/12/31.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given an array of integers, every element appears three times except for one. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 
 */

class Solution {
public:
    int singleNumber(int A[], int n) {
        int times[32] = {0};
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 32; ++j) {
                times[j] += (A[i] & (1 << j)) ? 1 : 0;
            }
        }
        
        int number = 0;
        for (int i = 0; i < 32; ++i)
        {
            number |= ((times[i] % 3) << i);
        }
        
        return number;
    }
    
};
