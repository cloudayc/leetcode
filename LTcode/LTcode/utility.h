//
//  utility.h
//  LTcode
//
//  Created by wyq on 14/12/2.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

#ifndef LTcode_utility_h
#define LTcode_utility_h

#include "commonHeader.h"

class Utility
{
public:
    TreeNode *factory(int depth);
    void postorder(TreeNode* p, int indent=0);
    void print(TreeNode *root);
};

#endif
