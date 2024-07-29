#include "LinkedListCircle.h"
#include <iostream>


using namespace std;

bool LinkedListCircle::hasCycle(ListNode *head){

    if(head == NULL) return false;
       ListNode* slow = head;
        ListNode* fast = head;

        while(slow != NULL && fast == NULL ){

            slow = slow->next;
            if(slow == NULL) return false;

            fast = fast->next->next;

            if(fast == NULL) return false;

            if(slow == fast) return true;
        }
        return false;   
}

void RunLinkedListCircle(){
    
    ListNode* a = new ListNode(3);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(0);
    ListNode* d = new ListNode(-4);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;
    

    auto* sln = new LinkedListCircle();

    sln->hasCycle(a);

}

ListNode* CreateLinkedList(int* array, int size){

    if(size < 0) return NULL;

    ListNode* head = NULL;
    ListNode* previous = NULL;

    for(int i=0;i<size;i++){
        ListNode* node = new ListNode(array[i]);
        if(head == NULL){
            head = node;
            previous = head;
        }
        else{
            previous->next = node;
            previous = node;
        }
    }

    return head;
}

void PrintLinkedList(ListNode* head){
    ListNode* current = head;
    while (current != NULL)
    {
        cout << current->val << endl;
        current = current->next;
    }
    
}

