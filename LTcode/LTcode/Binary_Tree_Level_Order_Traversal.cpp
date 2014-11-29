//
//  Binary_Tree_Level_Order_Traversal.cpp
//  LTcode
//
//  Created by wyq on 14/11/26.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 
 For example:
 Given binary tree {3,9,20,#,#,15,7},
 3
 / \
 9  20
 /  \
 15   7
 return its level order traversal as:
 [
     [3],
     [9,20],
     [15,7]
 ]
 confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.https://oj.leetcode.com/problems/binary-tree-level-order-traversal/#
 
 */

/**
 * Definition for binary tree
 */
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void calc()
    {
        
    }
    
    vector<vector<int> > levelOrder(TreeNode *root) {
        
        vector<vector<int> > v;
        if (!root) {
            return v;
        }
        vector<TreeNode *> list;
        list.push_back(root);
        
        while (!list.empty()) {
            vector<int> iv;
            vector<TreeNode *> tlist;
            for (vector<TreeNode *>::iterator iter = list.begin(); iter!= list.end(); ++iter)
            {
                iv.push_back((*iter)->val);
                if ((*iter)->left)
                    tlist.push_back((*iter)->left);
                if ((*iter)->right)
                    tlist.push_back((*iter)->right);
            }
            list.clear();
            list = tlist;
            
            v.push_back(iv);
            // levelOrderBottom
//            v.insert(v.begin(), iv);
        }
        return v;
    }
};