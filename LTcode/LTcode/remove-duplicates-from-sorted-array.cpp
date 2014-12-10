//
//  remove-duplicates-from-sorted-array.cpp
//  LTcode
//
//  Created by wyq on 14/12/8.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//


/* Description:
 
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 For example,
 Given input array A = [1,1,2],
 
 Your function should return length = 2, and A is now [1,2].
 
 */

#include <stdio.h>

class Solution {
public:
    void calc()
    {
        while (1)
        {
            int len = 1;
            int a[len];
            for (int i = 0; i < len; ++i) {
                scanf("%d", &a[i]);
            }
            int n = this->removeDuplicates(a, len);
            
            for (int i = 0; i < len; ++i) {
                printf("%d", a[i]);
            }
            printf(" %d\n", n);
        }
    }
    int removeDuplicates(int A[], int n) {
        if (n <= 1)
            return n;
        int offset = 0;
        for (int i = 1; i < n; ++i)
        {
            if (A[i] != A[offset])
                A[++offset] = A[i];
        }
        return offset + 1;
    }
};