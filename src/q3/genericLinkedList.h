ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;


typedef void(*printFunction)(void* data);

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, printFunction print);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, printFunction print);

//Delete the element after the given el
void deleteAfter(listElement* after);

//Returns the number of elements in a linked list
int getLength(listElement* list);

//Push a new element onto the head of a list.
//Update the list reference using side effects.
void push(listElement** list, void* data, size_t size, printFunction print);

listElement* pop(listElement** list);

void enqueue(listElement** list, void* data, size_t size, printFunction print);

listElement* dequeue(listElement* list);

#endif