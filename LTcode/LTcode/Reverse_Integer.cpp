//
//  Reverse_Integer.cpp
//  LTcode
//
//  Created by wyq on 14/11/24.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Reverse digits of an integer.
 
 Example1: x = 123, return 321
 Example2: x = -123, return -321
 
 */

#include <cstdlib>
#include <iostream>

class Solution {
public:
    void calc()
    {
        std::cout << this->reverse(123456) << std::endl;
    }
    
    int reverse(int x) {
        
        int int_max = 2147483647;
        
        int origin = x;
        int reverse = 0;
        for (int i = 0; origin; ++i, origin /= 10)
        {
            int digit = origin % 10;
            
            if (i >= 9)
            {
                int abs_reverse = abs(reverse);
                int abs_digit = abs(digit);
                
                int int_max_divide_10 = int_max / 10;
                int int_max_mod_10 = int_max % 10;
                
                if (abs_reverse > int_max_divide_10)
                    return 0;
                if (abs_reverse == int_max_divide_10)
                {
                    // may be never triggered
                    if (abs_digit > int_max_mod_10)
                        return 0;
                    if (x < 0 && abs_digit > int_max_mod_10 + 1)
                        return 0;
                }
            }
            reverse *= 10;
            reverse += digit;
        }
        return reverse;
    }
};