//
//  path-sum-ii.cpp
//  LTcode
//
//  Created by cloudayc on 11/29/14.
//  Copyright (c) 2014 cloudayc. All rights reserved.
//

/* Description:
 
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 
 For example:
 Given the below binary tree and sum = 22,
 5
 / \
 4   8
 /   / \
 11  13  4
 /  \    / \
 7    2  5   1
 
 return
 [
 [5,4,11,2],
 [5,8,4,5]
 ]
 
 */


/**
 * Definition for binary tree
 */
#include "utility.h"

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;



class Solution {
public:
    void calc()
    {
        TreeNode *root = Utility::factory(5);
        Utility::printTree(root);
        
        int sum = 0;
        while (true) {
            cin >> sum;
            vector<vector<int> >v = this->pathSum(root, sum);
            for (vector<vector<int> >::iterator iter = v.begin(); iter != v.end(); ++iter) {
                for (vector<int>::iterator in_iter = iter->begin(); in_iter != iter->end(); ++in_iter) {
                    cout << *in_iter << ends;
                }
                cout << endl;
            }
        }
    }
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        
        vector<vector<int> > v;
        if (!root)
            return v;
        
        int s = 0;
        
        int bitLeft = 0x02;
        int bitRight = 0x01;
        int bitAdded = 0x04;
        
        vector<TreeNode *> nodeStack;
        nodeStack.push_back(root);
        
        stack<int> statusStack;
        statusStack.push(0);
        
        while (!nodeStack.empty()) {
            TreeNode *node = nodeStack.back();
            
            int status = statusStack.top();
            if (!(status & bitAdded))
            {
                s += node->val;
                status |= bitAdded;
                statusStack.pop();
                statusStack.push(status);
            }
            
            if (!(status & bitLeft))
            {
                status |= bitLeft;
                statusStack.pop();
                statusStack.push(status);
                if (node->left)
                {
                    nodeStack.push_back(node->left);
                    statusStack.push(0);
                }
            }
            else if (!(status & bitRight))
            {
                status |= bitRight;
                statusStack.pop();
                statusStack.push(status);
                if (node->right)
                {
                    nodeStack.push_back(node->right);
                    statusStack.push(0);
                }
            }
            else
            {
                if (!node->left && !node->right && s == sum)
                {
                    vector<int> val;
                    for (vector<TreeNode *>::iterator iter = nodeStack.begin(); iter != nodeStack.end(); ++iter) {
                        val.push_back((*iter)->val);
                    }
                    v.push_back(val);
                }
                nodeStack.pop_back();
                statusStack.pop();
                s -= node->val;
            }
        }
        
        return v;
    }
};