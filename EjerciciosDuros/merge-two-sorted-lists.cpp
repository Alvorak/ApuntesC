//Sacado de => https://leetcode.com/problems/merge-two-sorted-lists/
//Written And Directed By Alvorak:
/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/
#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode listaMerged;
        ListNode *current = &listaMerged;
        while (list1 != nullptr && list2 != nullptr)
        {
            // comparar list1->val y list2->val
            if (list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
                current = current->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
                current = current->next;
            }
        }
        if (list1 == nullptr)
        {
            while (list2 != nullptr)
            {
                current->next = list2;
                list2 = list2->next;
                current = current->next;
            }
        }
        else
        {
            while (list1 != nullptr)
            {
                current->next = list1;
                list1 = list1->next;
                current = current->next;
            }
        }
        return listaMerged.next;
    }
};
