//
//  merge-k-sorted-lists.cpp
//  LTcode
//
//  Created by wyq on 14/12/9.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 
 */

#include "commonHeader.h"

using namespace std;

class Solution {
public:
    ListNode *mergeList(ListNode *olist, ListNode *tlist)
    {
        if (!olist && !tlist)
            return NULL;
        if (!olist)
            return tlist;
        if (!tlist)
            return olist;
        
        ListNode *head = NULL;
        if (olist->val <= tlist->val)
        {
            head = olist;
            olist = olist->next;
        }
        else
        {
            head = tlist;
            tlist = tlist->next;
        }
        
        ListNode *floatHead = head;
        while (olist || tlist)
        {
            if (!tlist)
            {
                floatHead->next = olist;
                break;
            }
            if (!olist)
            {
                floatHead->next = tlist;
                break;
            }
            if (olist->val <= tlist->val)
            {
                floatHead->next = olist;
                olist = olist->next;
            }
            else
            {
                floatHead->next = tlist;
                tlist = tlist->next;
            }
            floatHead = floatHead->next;
        }
        
        return head;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
        ListNode *head = nullptr;
        
        for (vector<ListNode *>::iterator iter = lists.begin(); iter != lists.end(); ++iter)
        {
            if (!head)
            {
                head = *iter;
            }
            else
            {
                head = this->mergeList(head, *iter);
            }
        }
        return head;
    }
};