#pragma once
#include "LinkedList.hpp"
using namespace std;

ListNode* findDetachedLast(ListNode* head)
{
    ListNode* last = head;
    if (head == nullptr || head->next == nullptr)
        return head;

    while (last->next->next != nullptr)
    {
        last = last->next;
    }
    ListNode* temp = last;
    last = last->next;
    temp->next = nullptr;
    return last;
}

ListNode* reverse(ListNode* head)
{
    ListNode* rNeck = nullptr;
    ListNode* neck = nullptr;

    while (head != nullptr)
    {
        neck = head->next;
        head->next = rNeck;
        rNeck = head;
        head = neck;
    }
    return rNeck;
}

ListNode* findLast(ListNode* head)
{
    ListNode* last = head;
    if (head == nullptr || head->next == nullptr)
        return head;

    while (last->next != nullptr)
    {
        last = last->next;
    }
    return last;
}
ListNode* findMid(ListNode* head)
{
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* findOneBeforeMid(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    return prev;
}

void reorderList(ListNode* head) {
    ListNode* cur = head;
    ListNode* next = head;
    ListNode* mid = findMid(head);
    ListNode* last = findDetachedLast(head);;
    while (mid != findLast(head))
    {
        last->next = cur->next;
        cur->next = last;
        cur = last->next;
        last = findDetachedLast(head);
    }
    last->next = cur->next;
    cur->next = last;
    mid->next = nullptr;
}
ListNode* makeList(int counterLimit)
{   
    if (counterLimit == 0)
        return nullptr;
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    int counter = 1;
    while (counter < counterLimit)
    {
        counter++;
        ListNode* temp = new ListNode(1 + counter);
        cur->next = temp;
        cur = cur->next;
    }
    return head;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            cur->next = list1;
            list1 = list1->next;
        }
        else
        {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    if (list1)
    {
        cur->next = list1;
    }
    if (list2)
    {
        cur->next = list2;
    }
    return dummy.next;
}

ListNode* mergeSortLinkedList(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* mid = findOneBeforeMid(head);
    ListNode* rightHalf = mid->next;
    ListNode* leftHalf = head;
    if (mid != nullptr)
        mid->next = nullptr;
    ListNode* l1 = mergeSortLinkedList(leftHalf);
    ListNode* l2 = mergeSortLinkedList(rightHalf);
    return mergeTwoLists(l1, l2);
}

ListNode* insertionSortList(ListNode* head) {
    // nothing to do if 1 or 0 nodes
    if (head == nullptr || head->next == nullptr)
        return head;
    ListNode* cur = head->next;
    ListNode* prev = nullptr;

    ListNode* newListHead = head;
    newListHead->next = nullptr;
    while (cur != nullptr)
    {
        prev = nullptr;
        // case 1, smaller than all element in list, update head
        if (cur->val <= newListHead->val)
        {
            ListNode* temp = cur->next;
            cur->next = newListHead;
            newListHead = cur;
            cur = temp;
        }
        else
        {
            ListNode* insertPos = newListHead;
            while (insertPos != nullptr && cur->val > insertPos->val)
            {
                prev = insertPos;
                insertPos = insertPos->next;
            }
            // case 2. new element greater than all exisiting element in list
            if (insertPos == nullptr)
            {
                insertPos = prev; // get last element
                ListNode* temp = cur;
                cur = cur->next;
                temp->next = nullptr;
                insertPos->next = temp;
            }
            else // case 3, insert in middle of list
            {
                ListNode* temp = cur;
                cur = cur->next;
                prev->next = temp;
                temp->next = insertPos;
            }

        }
    }

    return newListHead;

}