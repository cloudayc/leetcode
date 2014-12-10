//
//  remove-duplicates-from-sorted-list.cpp
//  LTcode
//
//  Created by wyq on 14/12/10.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.
 
 */

#include "commonHeader.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *floatHead = head;
        ListNode *L = head;
        floatHead = head->next;
        while (floatHead != NULL) {
            if (floatHead->val != L->val)
            {
                L = L->next;
                L->val = floatHead->val;
            }
            floatHead = floatHead->next;
        }
        L->next = NULL;
        return head;
    }
};