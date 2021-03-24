#include<stdio.h>
#include<stdlib.h>
  struct listNode{
  char data;
  struct listnode *nextptr;
};
void insert(ListNodePtr *sptr ,char item);
typedef struct listNode ListNode;
typedef  listNode *ListNodePtr;
int main(){
  char item;
ListNodePtr startPtr = NULL;
printf("inserisci caratteri");
scanf("%c",&item);
insert(&startPtr,item);
}
void insert(ListNodePtr *sptr ,char value){
  ListNodePtr new_ptr = malloc(sizeof(ListNode));
  if (new_ptr != NULL){
     new_ptr -> data = value;
     new_ptr -> nextptr= NULL;
    ListNodePtr preptr = NULL;
    ListNodePtr courrentptr = *sptr;
    while ( courrentptr != NULL && value < courrentptr -> data ){
      preptr = courrentptr;
      courrentptr = courrentptr -> nextptr;
    }
    if (preptr == NULL){
      new_ptr -> new_ptr = sptr;
      *sptr = new_ptr;
    }
    else{
      preptr -> nextptr = new_ptr;
      new_ptr -> nextptr = courrentptr;
    }
    else {
      printf("%c not iserited\n", value);
    }
  }
}
