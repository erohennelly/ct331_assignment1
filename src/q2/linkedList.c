#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct listElementStruct{
  char* data;
  size_t size;
  struct listElementStruct* next;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(char* data, size_t size){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }
  char* dataPointer = malloc(sizeof(char)*size);
  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  strcpy(dataPointer, data);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    printf("%s\n", current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, char* data, size_t size){
  listElement* newEl = createEl(data, size);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}
int getLength(listElement* list) {

	int length = 0;
	listElement* current = list;
	while (current != NULL) {
		
		current = current->next;
		length++;
	}
	return length;
}


//new element onto the head of a list
void push(listElement** list, char* data, size_t size) {

	listElement* newEl = createEl(data, size);
	//setting new element's next pointer as the head pointer that was passed in
	newEl->next = *list;
	*list = newEl;
}
//element from the head of a list.
listElement* pop(listElement** list) {

	listElement* head = *list;
	//creating node to store popped element which is the head of list
	listElement* poppedElement = createEl(head->data, head->size);
	//setting a newhead element as the node next to the head.
	listElement* newHead = head->next;
	*list = newHead;
	free(head->data);
	free(head);
	return poppedElement;
}
//same as push
void enqueue(listElement** list, char* data, size_t size) {
	listElement* newEl = createEl(data, size);
	newEl->next = *list;
	*list = newEl;
}

listElement* dequeue(listElement* list) {
	//store head of list in current
	listElement* current = list;
	listElement* deq;
	//find the last element and free that data inside it
	while (current != NULL) {
		//if last element == null - at the tail
		if (current->next->next == NULL) {

		    deq = createEl(current->next->data, current->next->size);
			free(current->next->data);
			free(current->next);
			//set 2nd last element pointing to NULL
			current->next = NULL;
		}
		current = current->next;
	}
	return deq;
}



