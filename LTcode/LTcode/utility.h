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
    static TreeNode *factory(int depth);
    static int treeDepth(TreeNode *root, int depth = 0);
    static void printTree(TreeNode *root);
    
    static void print(TreeNode *root);
};

#endif
