#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sumLinkedList.h"

LinkedList* createLinkedList() {
  LinkedList *pReturn = NULL;
  int i = 0;

  pReturn = (LinkedList *)malloc(sizeof(LinkedList));

  if (pReturn != NULL)
  {
    memset(pReturn, 0, sizeof(LinkedList));
  }
}

int addLinkedListNode(LinkedList *targetList, int position, ListNode element) {
  if (targetList == NULL) {
    return FALSE;
  }

  if (position < 0 || position > targetList->currentElementCount) {
    return FALSE;
  }

  ListNode* targetNode = NULL;
  ListNode* newNode = NULL;

  newNode = (ListNode *)malloc(sizeof(ListNode));

  if (newNode == NULL) {
    return;
  }

  targetNode = &(targetList->headerNode);

  for (int i = 0; i < position; i++) {
    targetNode = targetNode->nextNode;
  }

  newNode->nextNode = targetNode->nextNode;
  targetNode->nextNode = newNode->nextNode;

  targetList->currentElementCount += 1;

  return TRUE;
}

ListNode* getLinkedListElement(LinkedList *targetList, int position) {
  ListNode* targetNode = NULL;
  
  if (position < 0 || position > targetList->currentElementCount) {
    return targetNode;
  }

  targetNode = &(targetList->headerNode);

  for (int i = 0; i <= position; i++) {
    targetNode = targetNode->nextNode;
  }

  return targetNode;
}

int main(int argc, char const *argv[]) {
  int i = 0; 
  LinkedList *list = NULL, *list2 = NULL;
  ListNode node, node2;

  list = createLinkedList();
  list2 = createLinkeddList();

  node.number = 1;
  addLinkedListNode(list, 1, node);

  node.number = 2;
  addLinkedListNode(list, 2, node);

  node.number = 3;
  addLinkedListNode(list, 3, node);

  node2.number = 1;
  addLinkedListNode(list2, 1, node2);

  node2.number = 2;
  addLinkedListNode(list2, 2, node2);

  node2.number = 3;
  addLinkedListNode(list2, 3, node2);

  return 0;
}
