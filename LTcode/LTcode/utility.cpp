//
//  utility.cpp
//  LTcode
//
//  Created by wyq on 14/12/2.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//



#include "utility.h"

#include <string>
#include <vector>
#include <iomanip>

using namespace std;

TreeNode *Utility::factory(int depth)
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

void Utility::postorder(TreeNode* p, int indent)
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

void Utility::print(TreeNode *root)
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

