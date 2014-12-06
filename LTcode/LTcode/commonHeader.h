//
//  commonHeader.h
//  LTcode
//
//  Created by wyq on 14/12/2.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

#ifndef LTcode_commonHeader_h
#define LTcode_commonHeader_h

#include <iostream>

enum type_node{
    top = -1,
    l = 0,
    r
};

struct TreeNode {
    int val;
    type_node type;
    
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x, type_node t = top) : val(x), type(t), left(NULL), right(NULL) {}
};

#endif
