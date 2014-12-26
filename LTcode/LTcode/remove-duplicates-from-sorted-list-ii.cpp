//
//  remove-duplicates-from-sorted-list-ii.cpp
//  LTcode
//
//  Created by wyq on 14/12/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.
 
 */

#include "commonHeader.h"

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return NULL;
        ListNode *L = new ListNode(0);
        
        L->next = head;
        ListNode *point = L;
        
        bool duplicated = false;
        while (point->next != NULL)
        {
            if (point->next->next
                && point->next->val == point->next->next->val)
            {
                duplicated = true;
                point->next = point->next->next;
            }
            else
            {
                if (duplicated)
                {
                    point->next = point->next->next;
                    duplicated = false;
                }
                else
                {
                    point = point->next;
                }
            }
        }
        
        return L->next;
    }
};