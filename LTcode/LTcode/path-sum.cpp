//
//  path-sum.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \      \
 7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 
 */


/**
 * Definition for binary tree
 */
#include "utility.h"

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    
    void calc()
    {
        TreeNode *root = Utility::factory(6);
        Utility::printTree(root);
        
        int sum = 0;
        cin >> sum;
        this->hasPathSum(root, sum);
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        
        int s = 0;
        
        stack<TreeNode *> nodeStack;
        nodeStack.push(root);
        
        stack<int> statusStack;
        
        while (!nodeStack.empty()) {
            TreeNode *node = nodeStack.top();
            
            if (nodeStack.size() > statusStack.size())
            {
                s += node->val;
                statusStack.push(0);
            }
            int status = statusStack.top();
            if (!(status & 0x02))
            {
                statusStack.pop();
                statusStack.push(status | 0x02);
                if (node->left)
                {
                    nodeStack.push(node->left);
                    statusStack.push(0);
                }
            }
            else if (!(status & 0x01))
            {
                statusStack.pop();
                statusStack.push(status | 0x01);
                if (node->right)
                {
                    nodeStack.push(node->right);
                    statusStack.push(0);
                }
            }
            else
            {
                if (s == sum)
                    return true;
                nodeStack.pop();
                statusStack.pop();
                s -= node->val;
            }
        }
        
        return false;
    }
};