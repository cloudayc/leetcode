//
//  copy-list-with-random-pointer.cpp
//  LTcode
//
//  Created by wyq on 14/12/9.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 
 Return a deep copy of the list.
 
 */

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

#include <map>
#include "commonHeader.h"
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head)
            return NULL;
        
        RandomListNode *RL = new RandomListNode(0);
        RandomListNode *HL = RL;

        map<int, RandomListNode *> i2RLmap;
        map<RandomListNode *, int> r2Imap;
        while (head)
        {
            RL->next = new RandomListNode(head->label);
            if (head->random)
                r2Imap[RL->next] = head->random->label;
            i2RLmap[head->label] = RL->next;
            RL = RL->next;
            head = head->next;
        }
        
        map<int, RandomListNode *>::iterator it;
        for (map<RandomListNode *, int>::iterator iter = r2Imap.begin(); iter != r2Imap.end(); ++iter)
        {
            it = i2RLmap.find(iter->second);
            if (it != i2RLmap.end())
            {
                iter->first->random = it->second;
            }
        }
        
        return HL->next;
    }
};