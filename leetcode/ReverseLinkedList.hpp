#include <cstddef>
#ifndef REVERSE_LINKED_LIST_H
#define REVERSE_LINKED_LIST_H



//Definition for singly-linked list.
 struct ListNode {
      int val;
        ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
struct CopyResult{
    ListNode* head;
    ListNode* tail;

    CopyResult(ListNode* h, ListNode* t){
        head = h;
        tail= t;
    }
};

class ReverseLinkedList {
public:
    ListNode* reverseList(ListNode* head);
    ListNode* ReverseListAt(ListNode* head, int left, int right);
    CopyResult* CopyLinkedList(ListNode* head, int left, int right);
    ListNode* SwapPairs(ListNode* head);
    void PrintLinkedList(ListNode* head);

};


void RunReverseLinkedList();

#endif