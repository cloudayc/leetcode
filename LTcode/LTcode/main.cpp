//
//  main.cpp
//  LTcode
//
//  Created by wyq on 14/11/24.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

#include <iostream>

#include "Reverse_Integer.cpp"

int main(int argc, const char * argv[]) {

    Solution *s = new Solution();
    std::cout << s->reverse(123456) << std::endl;
    
    delete s;
    
    return 0;
}
