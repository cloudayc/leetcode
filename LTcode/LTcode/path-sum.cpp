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
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *factory(int depth)
    {
        if (!depth)
            return NULL;
        if (depth < 3 && arc4random() % 10 <= 3)
            return NULL;
        
        TreeNode *node = new TreeNode(arc4random() % 20);
        node->left = this->factory(depth - 1);
        node->right = this->factory(depth - 1);
        return node;
    }
    
    void print(TreeNode *root)
    {
        vector<TreeNode *> v;
        v.push_back(root);
        
        while (!v.empty()) {
            vector<TreeNode *> tv(v);
            v.clear();
            
            bool hasValidNode = false;
            string symbol("");
            for (vector<TreeNode *>::iterator iter = tv.begin(); iter != tv.end(); ++iter)
            {
                if ((*iter)->val == INT_MAX)
                    cout << '*' << "  ";
                else
                    cout << (*iter)->val << "  ";
                
                if ((*iter)->left)
                {
                    hasValidNode = true;
                    v.push_back((*iter));
                    symbol.append("/ ");
                }
                else
                {
                    TreeNode *node = new TreeNode(INT_MAX); // mem leak
                    v.push_back(node);
                    symbol.append("- ");
                }
                if ((*iter)->right)
                {
                    hasValidNode = true;
                    v.push_back((*iter));
                    symbol.append("\\ ");
                }
                else
                {
                    TreeNode *node = new TreeNode(INT_MAX); // mem leak
                    v.push_back(node);
                    symbol.append("- ");
                }
            }
            cout << endl;
            if (hasValidNode)
                cout << symbol << endl;
            else
                v.clear();
            
        }
    }
    
    void calc()
    {
        TreeNode *root = this->factory(3);
        print(root);
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