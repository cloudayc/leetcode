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
    
    node->left = Utility::factory(depth - 1, l);
    node->right = Utility::factory(depth - 1, r);
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
                ostream_symbol << ((*iter)->type == r ? " " : " ");
                spaceOvermuch = 0;
            }
            else
            {
                spaceOvermuch = Utility::countOfDigit((*iter)->val) - 1;
                ostream_value << (*iter)->val;
                ostream_symbol << ((*iter)->type == r ? "\\" : "/");
            }
            
            TreeNode *node = nullptr;
            if ((*iter)->left)
            {
                node = (*iter)->left;
                hasValideNode = true;
            }
            else
                node = new TreeNode(INT_MAX, l);
            v.push_back(node);
            
            if ((*iter)->right)
            {
                node = (*iter)->right;
                hasValideNode = true;
            }
            else
                node = new TreeNode(INT_MAX, r);
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
                symbol.append(" ");
            }
            else
            {
                TreeNode *node = new TreeNode(INT_MAX); // mem leak
                v.push_back(node);
                symbol.append(" ");
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

