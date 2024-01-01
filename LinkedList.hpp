struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};
//typedef struct DblNode {
//    int val;
//    DblNode* prev;
//    DblNode* next;
//    DblNode() : val(0), prev(nullptr), next(nullptr) {}
//    DblNode(int newVal) : val(newVal), prev(nullptr), next(nullptr) {
//    }
//    DblNode(int newVal, DblNode* prev, DblNode* next) : val(newVal), prev(prev), next(next) {
//    }
//};
ListNode* findDetachedLast(ListNode* head);

ListNode* reverse(ListNode* head);

ListNode* findLast(ListNode* head);

ListNode* findMid(ListNode* head);

void reorderList(ListNode* head);

ListNode* makeList(int counterLimit);

ListNode* insertionSortList(ListNode* head);

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
ListNode* mergeSortLinkedList(ListNode* head);