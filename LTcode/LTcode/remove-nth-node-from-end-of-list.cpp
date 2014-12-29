//
//  remove-nth-node-from-end-of-list.cpp
//  LTcode
//
//  Created by wyq on 14/12/25.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Note:
 Given n will always be valid.
 Try to do this in one pass.
 
 Given a linked list, remove the nth node from the end of list and return its head.
 
 For example,
 
 Given linked list: 1->2->3->4->5, and n = 2.
 
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 
 
 
 */

#include "commonHeader.h"

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head)
            return NULL;
        ListNode *L = new ListNode(0);
        L->next = head;
        ListNode *H = L;
        
        ListNode *point = head;
        while (point != NULL)
        {
            if (n > 0)
            {
                --n;
            }
            else
            {
                L = L->next;
            }
            point = point->next;
        }
        L->next = L->next->next;
        
        return H->next;
    }
};