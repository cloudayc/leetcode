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
#include <sstream>

using namespace std;

TreeNode *Utility::factory(int depth, type_node t)
{
    if (!depth)
        return NULL;
    if (depth < 3 && arc4random() % 10 <= 3)
        return NULL;
    
    TreeNode *node = new TreeNode(arc4random() % 20);
    node->type = t;
    
    node->left = Utility::factory(depth - 1, bNode_l);
    node->right = Utility::factory(depth - 1, bNode_r);
    return node;
}

int Utility::countOfDigit(int digit)
{
    if (digit == 0)
        return 1;
    int cnt = 0;
    while (digit)
    {
        cnt++;
        digit /= 10;
    }
    return cnt;
}

void Utility::printTree(TreeNode *root)
{
    int depth = Utility::treeDepth(root);
    int maxLeafCount = 1 << (depth - 1);
    int leafLength = maxLeafCount * 2 - 1;
    
    int innerSpaceLen = 0;
    int prefixSpaceLen = leafLength / 2;
    
    char noneValue = ' ';
    char spaceChar = ' ';
    int spaceCharIncrease = 4;
    
    vector<TreeNode *> v;
    v.push_back(root);
    
    stringstream ostream_symbol;
    stringstream ostream_value;
    while (!v.empty())
    {
        vector<TreeNode *> tv(v);
        v.clear();
        
        // print prefix spaces
        ostream_value << string(prefixSpaceLen * spaceCharIncrease, spaceChar);
        ostream_symbol << string(prefixSpaceLen * spaceCharIncrease, spaceChar);
        
        // calc inner space count
        innerSpaceLen = 0;
        
        int spaceOvermuch = 0;
        bool hasValideNode = false;
        
        for (vector<TreeNode *>::iterator iter = tv.begin(); iter != tv.end(); ++iter)
        {
            // print inner spaces, empty "" at the beginning
            ostream_value << string((innerSpaceLen * 2 + 1) * spaceCharIncrease + 3 - spaceOvermuch, spaceChar);
            ostream_symbol << string((innerSpaceLen * 2 + 1) * spaceCharIncrease + 3, spaceChar);
            
            innerSpaceLen = prefixSpaceLen;
            
            // print value
            if ((*iter)->val == INT_MAX)
            {
                ostream_value << noneValue;
                ostream_symbol << ((*iter)->type == bNode_r ? " " : " ");
                spaceOvermuch = 0;
            }
            else
            {
                spaceOvermuch = Utility::countOfDigit((*iter)->val) - 1;
                ostream_value << (*iter)->val;
                ostream_symbol << ((*iter)->type == bNode_r ? "\\" : "/");
            }
            
            TreeNode *node = nullptr;
            if ((*iter)->left)
            {
                node = (*iter)->left;
                hasValideNode = true;
            }
            else
                node = new TreeNode(INT_MAX, bNode_l);
            v.push_back(node);
            
            if ((*iter)->right)
            {
                node = (*iter)->right;
                hasValideNode = true;
            }
            else
                node = new TreeNode(INT_MAX, bNode_r);
            v.push_back(node);
        }
        ostream_value << endl;
        ostream_symbol << endl;
        
        cout << ostream_symbol.str();
        cout << ostream_value.str();
        ostream_value.str("");
        ostream_symbol.str("");
        
        if (!hasValideNode)
            v.clear();
        
        // calc prefix spaces
        prefixSpaceLen /= 2;
    }
}

int Utility::treeDepth(TreeNode *root, int depth)
{
    if (root == NULL)
        return depth;
    return max(Utility::treeDepth(root->left, depth),
               Utility::treeDepth(root->right, depth)) + 1;
}


