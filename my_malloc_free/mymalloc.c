#include<stdio.h>
#include<stddef.h>
#include "mymalloc.h"


void initialize(){
 freeList->size=20000-sizeof(struct block);
 freeList->free=1;
 freeList->next=NULL;
}


void split(struct block *fitting_slot,size_t size){
 struct block *new=(void*)((void*)fitting_slot+size+sizeof(struct block));
 new->size=(fitting_slot->size)-size-sizeof(struct block);
 new->free=1;
 new->next=fitting_slot->next;
 fitting_slot->size=size;
 fitting_slot->free=0;
 fitting_slot->next=new;
}


void merge(){
 struct block *curr,*prev;
 curr=freeList;
 while((curr->next)!=NULL){
  if((curr->free) && (curr->next->free)){
   curr->size+=(curr->next->size)+sizeof(struct block);
   curr->next=curr->next->next;
  }
  prev=curr;
  curr=curr->next;
 }
}


void *MyMalloc(size_t noOfBytes){
  
 //add your code below this line
    struct block *curr, *prev;
    void *result = NULL;

    // Initialize memory if it hasn't been initialized
    if (freeList->size == 0) {
        initialize();
    }

    curr = freeList;
    while (curr != NULL) {
        if (curr->free) {
            if (curr->size == noOfBytes) {
                // Block exactly fits the request
                curr->free = 0;
                result = (void*)(++curr);
                break;
            } else if (curr->size > (noOfBytes + sizeof(struct block))) {
                // Block is too large, split it
                split(curr, noOfBytes);
                result = (void*)(++curr);
                break;
            }
        }
        prev = curr;
        curr = curr->next;
    }

    // Merge consecutive free blocks
    merge();

    if (result == NULL) {
        printf("Sorry. No sufficient memory to allocate.\n");
    }

    return result;
 
 
 //add your code above this line
}


void MyFree(void* ptr){
  
 //add your code below this line
     // Verify the address is within the address range of our memory array
    if (ptr > (void*)memory && ptr < (void*)(memory + 20000)) {
        struct block* blockToFree = (struct block*)(ptr - sizeof(struct block));
        blockToFree->free = 1;

        // Merge consecutive free blocks
        merge();
    } else {
        printf("Please provide a valid allocated pointer.\n");
    }
 
 
 //add your code above this line
}