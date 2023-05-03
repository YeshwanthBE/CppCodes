#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#define MAXSKIPLEVEL 5
using namespace std;
struct ListNode {
  int data;
  struct ListNode * next[1];
};
struct SkipList {
  struct ListNode * header;
  int listLevel;
};
struct SkipList list;
struct ListNode * insertElement(int data) {
  int i, newLevel;
  struct ListNode * update[MAXSKIPLEVEL + 1];
  struct ListNode * temp;
  temp = list.header;
  for (i = list.listLevel; i >= 0; i--) {
    while (temp -> next[i] != list.header && temp -> next[i] -> data < data);
    update[i] = temp;
  }
  temp = temp -> next[0];
  if (temp != list.header && temp -> data == data)
    return (temp);
  for (newLevel = 0; rand() < RAND_MAX / 2 && newLevel < MAXSKIPLEVEL; newLevel++);
  for (i = list.listLevel + 1; i < newLevel; i++)

    if (newLevel > list.listLevel) {
      for (i = list.listLevel + 1; i <= newLevel; i++)
        update[i] = list.header,

        list.listLevel = newLevel;
    }
temp =(ListNode *) malloc(sizeof(ListNode) + newLevel * sizeof(ListNode * ));

  temp -> data = data;

  for (i = 0; i < newLevel; i++) {
    temp -> next[i] = update[i] -> next[i];
    update[i] -> next[i] = temp;
  }
  return (temp);
}
    void initList() {

        int i;
        list.header = (ListNode *)malloc(sizeof(struct ListNode));
        for (i = 0; i <= MAXSKIPLEVEL; i++)
        list.header -> next[i] = list.header;
        list.listLevel = 0;
      }
      int main() {

        int i, * a, maxnum = 5;
        initList();
        a=(int *)malloc(maxnum*sizeof(*a));

          for (i = 0; i < maxnum; i++) a[i] = rand();
        printf("Random, %d items in", maxnum);
        //for (i = 0; i < maxnum; i++)
            insertElement(1);
        return 0;
      }
