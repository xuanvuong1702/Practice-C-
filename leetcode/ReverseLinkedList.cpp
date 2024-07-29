#include "ReverseLinkedList.hpp"
#include <cstddef>
#include <iostream>


using namespace std;

ListNode* ReverseLinkedList::reverseList(ListNode* head){
    //init
    ListNode* newNext  = NULL;
    ListNode* current = head;
    ListNode* oldNext = current->next;
    ListNode* newHead = NULL;

    while(current != NULL){

        if(newNext == NULL){
            current->next = newNext;
            newNext = current;
            newHead = current;
        }

        current = oldNext;

        if(current != NULL){
            oldNext = current->next;
            current->next = newNext;
            newNext = current;
            newHead = current;
        }
        
    }

    return newHead;
}

 ListNode* ReverseLinkedList::ReverseListAt(ListNode* head, int left, int right){

    CopyResult* subLinkedList = CopyLinkedList(head, left, right);

    ListNode* reversedSub = reverseList(subLinkedList->head);

    ListNode* current = head;
    ListNode* previous = NULL;

    ListNode* newHead = NULL;
    ListNode* newCurrent = newHead;

    int index = 1;

    while(current != NULL){

        if(index < left || index > right){
            ListNode* item  = new ListNode(current->val);
            if(newCurrent == NULL){
                newHead = item;
                newCurrent = newHead;
            }
            else{
                newCurrent->next = item;
                newCurrent = item;
            }
        }

        if(index == left){
            if(newHead == NULL){
                newHead = reversedSub;
                newCurrent = subLinkedList->head;
            }
            else{
                newCurrent->next = reversedSub;
                newCurrent = subLinkedList->head;
            }
        }
        
        previous = current;
        current = current->next;
        index++;
    }

    return newHead;

 }

void ReverseLinkedList::PrintLinkedList(ListNode* head){
    ListNode* current = head;
    while(current != NULL){
        cout << current->val << endl;
        current = current->next;
    }

}



CopyResult* ReverseLinkedList::CopyLinkedList(ListNode* head, int left, int right){

    CopyResult* result;

    ListNode* current = head;

    ListNode* newHead;
    ListNode* newCurrent;
    ListNode* newTail;

    int index = 1;

    while (current != NULL)
    {   
        if(index == left){
            newHead = new ListNode(current->val);
            newCurrent = newHead;
            newTail = newHead;
        }

        if(index > left && index < right){
            ListNode* item = new ListNode(current->val);
            newCurrent->next = item;
            newCurrent = item;
            newTail = newCurrent;
        }

        if(index == right){
            if(left == right){
                newCurrent->next == NULL;
                newTail = newCurrent;
            }
            else{
                ListNode* item = new ListNode(current->val, NULL);
                newCurrent->next = item;
                newTail = item;
            }
            break;
        }
        
        index++;
        current = current->next;
    }

    return new CopyResult(newHead, newTail);
}

ListNode* ReverseLinkedList::SwapPairs(ListNode* head){
    int index = 1;
    int step = 2;

    ListNode* current = head;
    ListNode* newLinkedList = head;

    while(current != NULL){
        int left = index;
        int right = index + step -1;

        if(current->next == NULL) return newLinkedList;

        newLinkedList = ReverseListAt(newLinkedList, left, right);

        current = current->next->next;
        index += step;
    }

    return newLinkedList;
}

void RunReverseLinkedList(){
    ReverseLinkedList* sln = new ReverseLinkedList();

    ListNode* b = new ListNode(3);
    ListNode* c = new ListNode(2,b);
    ListNode* d = new ListNode(1,c);

    cout << "---" << endl;

    sln->PrintLinkedList(d);
    
    cout << "---" << endl;
    
    ListNode* reverse = sln->SwapPairs(d);

    cout << "---" << endl;

    sln->PrintLinkedList(reverse);
}

