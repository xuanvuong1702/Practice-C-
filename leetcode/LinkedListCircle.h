#include <cstddef>
#include <array>
#ifndef LINKED_LIST_CIRCLE_H
#define LINKED_LIST_CIRCLE_H

using namespace std;

 //Definition for singly-linked list.

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};


class LinkedListCircle {
    public:
        bool hasCycle(ListNode *head);
        

};

void RunLinkedListCircle();
ListNode* CreateLinkedList(int* array, int size);
void PrintLinkedList(ListNode* head);

#endif