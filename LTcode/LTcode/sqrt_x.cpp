//
//  sqrt_x.cpp
//  LTcode
//
//  Created by wyq on 14/11/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Implement int sqrt(int x).
 
 Compute and return the square root of x.

 */

#include <math.h>
#include <iostream>

class Solution {
public:
    void calc()
    {
        std::cout << this->sqrt(8) << std::endl;
        std::cout << sqrt(8) << std::endl;
        
    }
    
    int sqrt(int x) {
        if (x <= 0)
            return 0;
        if (x == 1)
            return 1;
        double left = 0;
        double right = x;
        while (true)
        {
            double mid = (right + left) / 2;
            double mul = mid * mid;
            if (x - mul > 1e-6)
            {
                left = mid;
            }
            else if (x - mul < -1e-6)
            {
                right = mid;
            }
            else
            {
                return mid;
            }
        }
        return 0;
    }
};