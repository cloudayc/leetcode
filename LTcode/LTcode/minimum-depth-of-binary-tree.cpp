//
//  minimum-depth-of-binary-tree.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a binary tree, find its minimum depth.
 
 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 
 */


/**
 * Definition for binary tree
 */
#include <iostream>

#include <vector>

#include "commonHeader.h"
using namespace std;

class Solution {
public:
    void calc()
    {
        
    }
    
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        
        vector<TreeNode *>v;
        v.push_back(root);
        
        int depth = 1;
        while (!v.empty())
        {
            vector<TreeNode *> tv(v);
            v.clear();
            
            for (vector<TreeNode *>::iterator iter = tv.begin(); iter != tv.end(); ++iter)
            {
                TreeNode *node = *iter;
                if (!node->left && !node->right)
                    return depth;
                if (node->left)
                    v.push_back(node->left);
                if (node->right)
                    v.push_back(node->right);
            }
            ++depth;
        }
        
        return 0;
    }
};