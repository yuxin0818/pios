//#include <stdio.h>

void write_zero();

extern long __bss_start;
extern long __bss_end;
extern struct ppage* free_list;

#include "linkedlist.h"
#include "led.h"
#include "serial.h"
#include "rprintf.h"
#include "page.h"

/*
struct list_element c = {NULL, 3};
struct list_element b = {&c, 2};
struct list_element a = {&b, 1};
struct list_element *head = &a;
*/



void kernel_main(){
	/*
	write_zero();
	led_init();
	
	print_list(head);
	add(head, 4);
	add(head, 5);
	remove_list(head, 4);
	print_list(head);
	
	esp_printf(putc, "The Memory Location is:   %x \n", kernel_main);
	*/

	init_pfa_list();
	struct ppage* test = free_list->next;
	esp_printf(putc, "Physcial addr:  %x \n", test->physical_addr);
	esp_printf(putc, "Physcial addr1:  %x \n", test->next->physical_addr);
	esp_printf(putc, "Physcial addr2:  %x \n", test->next->next->physical_addr);
	esp_printf(putc, "Physcial addr3:  %x \n", test->next->next->next->physical_addr);

	test = allocate_physical_pages(2);
	esp_printf(putc, "physical pages -->  %x \n", test);

	esp_printf(putc, "Physcial addr:  %x \n", test->physical_addr);
	esp_printf(putc, "physical page2: %x \n", test->next->physical_addr);
	/*
	esp_printf(putc, "Physcial addr1:  %x \n", test->next->physical_addr);
        esp_printf(putc, "Physcial addr2:  %x \n", test->next->next->physical_addr);
        esp_printf(putc, "Physcial addr3:  %x \n", test->next->next->next->physical_addr);
	*/

	free_physical_pages(test);
	test = free_list->next;
	esp_printf(putc, "After freeing:  %x \n", test->physical_addr);

        esp_printf(putc, "Physcial addr1:  %x \n", test->next->physical_addr);
        esp_printf(putc, "Physcial addr2:  %x \n", test->next->next->physical_addr);
        esp_printf(putc, "Physcial addr3:  %x \n", test->next->next->next->physical_addr);

	while (1) {
		/*
		led_on();
		delay(300);
		led_off();
		delay(300);
		*/
	}
}

void write_zero() {

	int x = 0;
	while ((&__bss_start)+x != &__bss_end) {
		(&__bss_start)[x] = 0;
		x++;
	}

}
