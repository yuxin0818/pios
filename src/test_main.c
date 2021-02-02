#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"



//void main() {
/* 
 * This flie used to test my add method and remove method
 */ 


struct list_element c = {NULL,3};
struct list_element b = {&c, 2};
struct list_element a = {&b, 1};
struct list_element *head = &a;


void main() {
	print_list(head);
	printf("%s\n", "hello2");
	add(head, 4);
	add(head, 5);
	printf("%s\n", "hello3");
	remove_list(head, 4);
	printf("%s\n", "hello4");
	print_list(head);
	
}
