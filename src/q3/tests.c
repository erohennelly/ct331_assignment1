#include <stdio.h>
#include "genericLinkedList.h"

void printString(void* data) {
	printf("%s\n", (char*)data);
}

void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

void printInt(void* data) {
	printf("%d\n", *(int*)data);
}
void printFloat(void* data) {
	printf("%f\n", *(float*)data);
}

void printDouble(void* data) {
	printf("%f\n", *(double*)data);
}

char stringTest[] = "A-Apple";
void *String = &stringTest;

char charTest = 'B';
void *Char = &charTest;

int  intTest = 3;
void *Int = &intTest;

float floatTest = 4.444444;
void *Float = &floatTest;

double doubleTest = 555555.555555;
void *Double = &doubleTest;

void runTests() {
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Tests running...\n\n");
	printf("Creating Generic Linked List...\n\n");
	listElement* l = createEl(String, sizeof(stringTest), printString);
	listElement* l2 = insertAfter(l, Char, sizeof(charTest), printChar);
	listElement* l3 = insertAfter(l2, Int, sizeof(intTest), printInt);
	listElement* l4 = insertAfter(l3, Float, sizeof(floatTest), printFloat);
	insertAfter(l4, Double, sizeof(doubleTest), printDouble);
	traverse(l);
	printf("\n");

	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Testing get Length function\n\n");
	printf("Length of list = %d\n", getLength(l));
	printf("\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Testing Push function (Pushing elements to head of the list)\n\n");
	printf("Pushing elements in order :  %s , %c , %d , %f , %f \n\n", stringTest, charTest, intTest, floatTest, doubleTest);
	printf("Before : \n\n");
	traverse(l);
	printf("\n");
	push(&l, String, sizeof(stringTest), printString);
	push(&l, Char, sizeof(charTest), printChar);
	push(&l, Int, sizeof(intTest), printInt);
	push(&l, Float, sizeof(floatTest), printFloat);
	push(&l, Double, sizeof(doubleTest), printDouble);
	printf("After : \n\n");
	traverse(l);
	printf("\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Testing Pop function (Popping element from the head of the list)\n\n");
	printf("Before : \n\n");
	traverse(l);
	printf("\n");
	listElement* popped = pop(&l);
	printf("After : \n\n");
	traverse(l);
	printf("\nPopped Element(s) : ");
	traverse(popped);
	printf("\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Testing Enqueue function (Enqueue element to the head of the list)\n\n");
	printf("Pushing elements in order :  %s , %c , %d , %f , %f \n\n", stringTest, charTest, intTest, floatTest, doubleTest);
	printf("Before : \n\n");
	traverse(l);
	printf("\n");
	enqueue(&l, String, sizeof(stringTest), printString);
	enqueue(&l, Char, sizeof(charTest), printChar);
	enqueue(&l, Int, sizeof(intTest), printInt);
	enqueue(&l, Float, sizeof(floatTest), printFloat);
	enqueue(&l, Double, sizeof(doubleTest), printDouble);
	printf("After : \n\n");
	traverse(l);
	printf("\n");
	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Testing dequeue function (Dequeue element from the tail of the list)\n\n");
	printf("Before : \n\n");
	traverse(l);
	printf("\n");
	listElement* deq = dequeue(l);
	printf("\n");
	printf("After : \n\n");
	traverse(l);
	printf("\nDequeued Element(s) : ");
	traverse(deq);
	printf("\n");
	printf("-------------------------------------------------------------------------------------------------\n");

	printf("\nTests complete.\n\n");

}