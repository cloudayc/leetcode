//
//  balanced-binary-tree.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a binary tree, determine if it is height-balanced.
 
 For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 
 */


/**
 * Definition for binary tree
 */
#include <iostream>

#include "commonHeader.h"


class Solution {
public:
    void calc()
    {
        
    }
    int checkBanlance(TreeNode * root, int depth)
    {
        if (!root)
            return depth;
        depth++;
        int leftDepth = this->checkBanlance(root->left, depth);
        int rightDepth = this->checkBanlance(root->right, depth);
        if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth - rightDepth) > 1)
            return -1;
        return leftDepth > rightDepth ? leftDepth : rightDepth;
    }
    
    bool isBalanced(TreeNode *root) {
        if (checkBanlance(root, 0) == -1)
            return false;
        return true;
    }
};