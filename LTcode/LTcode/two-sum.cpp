//
//  two-sum.cpp
//  LTcode
//
//  Created by wyq on 14/12/9.
//  Copyright (c) 2014年 cloudayc. All rights reserved.
//

/* Description:
 
 Given an array of integers, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 
 */

#include <map>
#include "commonHeader.h"
using namespace std;

class Solution {
public:
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vi;
        map<int, int> hash;
        for (int i = 0; i < numbers.size(); ++i)
        {
            map<int, int>::iterator iter = hash.find(numbers[i]);
            if (iter != hash.end() && iter->first + numbers[i] == target)
            {
                vi.push_back(iter->second + 1);
                vi.push_back(i + 1);
                return vi;
            }
            hash[numbers[i]] = i;
        }
        
        for (int i = 0; i < numbers.size(); ++i)
        {
            hash.erase(numbers[i]);
            map<int, int>::iterator iter = hash.find(target - numbers[i]);
            if (iter != hash.end())
            {
                vi.push_back(i + 1);
                vi.push_back(iter->second + 1);
            }
            hash[numbers[i]] = i;
        }
        
        return vi;
    }
};













class SolutionWrong {
public:
    int findNumber(vector<int> &numbers, int left, int target)
    {
        size_t l = left;
        size_t r = numbers.size() - 1;
        while (l <= r)
        {
            size_t mid = (l + r) / 2;
            if (numbers[mid] == target)
                return mid;
            else if (numbers[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int> &numbers, int target) {
        sort(numbers.begin(), numbers.end());
        vector<int> vi;
        for (int i = 0; i < numbers.size() - 1; ++i)
        {
            int re = this->findNumber(numbers, i + 1, target - numbers[i]);
            if (re != -1)
            {
                vi.push_back(i + 1);
                vi.push_back(re + 1);
            }
        }
        return vi;
    }
};