//
//  MergeTwoSortedLists.cpp
//  LTcode
//
//  Created by wyq on 14/11/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 
 */

/**
 * Definition for singly-linked list.
 */
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    void calc()
    {
        
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) return NULL;
        if (!l1) return l2;
        if (!l2) return l1;
        
        ListNode *head = NULL;
        if (l1->val <= l2->val)
        {
            head = l1;
            l1 = l1->next;
        }
        else
        {
            head = l2;
            l2 = l2->next;
        }
        ListNode *ln = head;
        
        while (l1 && l2)
        {
            if (l1 ->val <= l2->val)
            {
                ln->next = l1;
                l1 = l1->next;
            }
            else
            {
                ln->next = l2;
                l2 = l2->next;
            }
            ln = ln->next;
        }
        if (l1) ln->next = l1;
        if (l2) ln->next = l2;
        
        return head;
    }
};