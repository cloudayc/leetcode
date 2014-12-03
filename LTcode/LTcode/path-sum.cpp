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
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

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
    void postorder(TreeNode* p, int indent=0)
    {
        if(p != NULL) {
            if(p->left) postorder(p->left, indent+4);
            if(p->right) postorder(p->right, indent+4);
            if (indent) {
                std::cout << std::setw(indent) << ' ';
            }
            cout<< p->val << "\n ";
        }
    }
    
    void print(TreeNode *root)
    {
        vector<string> output;
        
        vector<TreeNode *> v;
        v.push_back(root);
        
        int spaceCnt = 32;
        while (!v.empty()) {
            vector<TreeNode *> tv(v);
            v.clear();
            
            bool hasValidNode = false;
            string symbol("");
            string values("");
            for (vector<TreeNode *>::iterator iter = tv.begin(); iter != tv.end(); ++iter)
            {
                if ((*iter)->val == INT_MAX)
                    values.append("*");
                else
                    values.append(to_string((*iter)->val));
                values.append("  ");
                
                if ((*iter)->left)
                {
                    hasValidNode = true;
                    v.push_back((*iter)->left);
//                    symbol.append("/");
                    symbol.append(" ");
                }
                else
                {
                    TreeNode *node = new TreeNode(INT_MAX); // mem leak
                    v.push_back(node);
                    symbol.append(" ");
//                    symbol.append("-");
                }
                
                values.append(string(spaceCnt, ' '));
                if ((*iter)->right)
                {
                    hasValidNode = true;
                    v.push_back((*iter)->right);
//                    symbol.append("\\");
                    symbol.append(" ");
                }
                else
                {
                    TreeNode *node = new TreeNode(INT_MAX); // mem leak
                    v.push_back(node);
                    symbol.append(" ");
                    //                    symbol.append("-");
                }
                symbol.append(string(spaceCnt, ' '));
//                symbol.append(" ");
            }
            spaceCnt /= 2;
        
            output.push_back(values);
            if (hasValidNode)
                output.push_back(symbol);
            else
                v.clear();
        }
        
        string last = output.back();
        size_t len = last.length() / 2;
        int flag = 0;
        int spaceCut = 1;
        for (vector<string>::iterator iter = output.begin(); iter != output.end(); ++iter)
        {
            cout << string(len - spaceCut, ' ');
//            cout << string(len, ' ');
            cout << *iter << endl;
            if (flag++ & 1)
            {
                len -= spaceCut;
                spaceCut *= 2;
            }
            if (len <= 0)
                len = 0;
        }
    }
    
    void calc()
    {
        TreeNode *root = Utility::factory(6);
        cout << Utility::treeDepth(root, 0) << endl;
        Utility::print(root);
//        TreeNode *root = this->factory(5);
//        postorder(root);
//        print(root);
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