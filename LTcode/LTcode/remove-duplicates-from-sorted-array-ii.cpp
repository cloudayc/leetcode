//
//  remove-duplicates-from-sorted-array-ii.cpp
//  LTcode
//
//  Created by wyq on 14/12/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 
 For example,
 Given sorted array A = [1,1,1,2,2,3],
 
 Your function should return length = 5, and A is now [1,1,2,2,3].
 
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 1)
            return n;
        
        int length = 1;
        
        int same = 1;
        for (int i = 1; i < n; ++i)
        {
            if (A[i] == A[i - 1])
            {
                if (same < 2)
                {
                    A[length++] = A[i];
                }
                same++;
            }
            else
            {
                A[length++] = A[i];
                same = 1;
            }
        }
        return length;
    }
};