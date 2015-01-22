//
//  maximum-subarray.cpp
//  LTcode
//
//  Created by wyq on 14/12/9.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 
 click to show more practice.
 https://oj.leetcode.com/problems/maximum-subarray/#
 
 */

#include <stdio.h>
class Solution {
public:
    
    void calc()
    {
//        while (1)
        {
            int len = 9;
            int a[] = {-2,1,-3,4,-1,2,1,-5,4};
//            for (int i = 0; i < len; ++i) {
//                scanf("%d", &a[i]);
//            }
            int n = this->maxSubArray(a, len);
            
            for (int i = 0; i < len; ++i) {
                printf("%d ", a[i]);
            }
            printf(" %d\n", n);
        }
    }
    
    int maxSubArray(int A[], int n) {
        if (n == 0)
            return 0;
        int maxSum = 0;
        int value =  -1e9;
        for (int i = 0; i < n; ++i)
        {
            maxSum += A[i];
            if (maxSum < 0)
                maxSum = 0;
            if (maxSum > value)
                value = maxSum;
        }
        return value;
    }
};