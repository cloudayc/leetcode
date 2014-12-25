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
// Last executed input:	[{2},{},{-1}]


class Solution{
public:
    
    void calc()
    {
        vector<ListNode *>v;
        ListNode *p = new ListNode(2);
        v.push_back(p);
        v.push_back(NULL);
        p = new ListNode(-1);
        v.push_back(p);
        ListNode *l = this->mergeKLists(v);
        int a = 0;
    }
    
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        
        for (vector<ListNode *>::iterator iter = lists.begin(); iter != lists.end(); )
        {
            if (*iter == NULL)
                iter = lists.erase(iter);
            else
                ++iter;
        }
        
        ListNode *head = this->binMerge(lists);
        
        return head;
    }
    
    ListNode *binMerge(vector<ListNode *>&lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return *lists.begin();
        
        vector<ListNode *>::iterator mid = lists.begin() + lists.size() / 2;
        
        vector<ListNode *>left(lists.begin(), mid);
        vector<ListNode *>right(mid, lists.end());
        
        return mergeList(this->binMerge(left), this->binMerge(right));
    }
    
    ListNode *mergeList(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
            return NULL;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode *head = new ListNode(0);
        head->next = l1;
        ListNode *fhead = head;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                l1 = l1->next;
            }
            else
            {
                ListNode *ltmp = l2->next;
                fhead->next = l2;
                l2->next = l1;
                l2 = ltmp;
            }
            fhead = fhead->next;
        }
        if (l2)
            fhead->next = l2;
        
        return head->next;
    }
};



class SolutionTLE {
public:
    void calc()
    {
        vector<ListNode *>v;
        ListNode *p = new ListNode(2);
        v.push_back(p);
        v.push_back(NULL);
        p = new ListNode(-1);
        v.push_back(p);
        ListNode *l = this->mergeKLists(v);
        int a = 0;
    }
    
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