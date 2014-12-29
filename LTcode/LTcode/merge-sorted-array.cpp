//
//  merge-sorted-array.cpp
//  LTcode
//
//  Created by wyq on 14/12/9.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given two sorted integer arrays A and B, merge B into A as one sorted array.
 
 Note:
 You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 
 */


class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index = m + n - 1;
        int pa = m - 1;
        int pb = n - 1;
        while (index >= 0)
        {
            if (pa >= 0 && pb >= 0)
            {
                if (A[pa] >= B[pb])
                {
                    A[index--] = A[pa--];
                }
                else
                {
                    A[index--] = B[pb--];
                }
            }
            else if (pa >=0 && pb < 0)
            {
                A[index--] = A[pa--];
            }
            else if (pb >= 0 && pa < 0)
            {
                A[index--] = B[pb--];
            }
        }
    }
};