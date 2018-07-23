#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType {
  int number;
  struct ListNodeType *nextNode;
} ListNode;

typedef struct LinkedListType {
  int currentElementCount;
  ListNode headerNode;
} LinkedList;

#define TRUE 1
#define FALSE 0

LinkedList *createLinkedList();
ListNode *getLinkedListElement(LinkedList *prevList, int position);
int addLinkedListNode(LinkedList *prevList, int position, ListNode element);

#endif