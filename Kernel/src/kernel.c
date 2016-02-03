#include <kernel.h>
#include <define.h>
#include <system.h>
#include <modules.h>
#include <memory.h>
#include <video.h>
#include <output.h>
#include <log.h>
#include <idt.h>
#include <interrupts.h>
#include <exceptions.h>
#include <pic.h>

#define PAGE_SIZE 0x1000

#define MODULE_SHELL_INDEX 0
#define MODULE_SHELL_ADDRESS 0x400000

extern uint8_t text;
extern uint8_t rodata;
extern uint8_t data;
extern uint8_t bss;
extern uint8_t endOfKernelBinary;
extern uint8_t endOfKernel;

typedef int (* EntryPoint)();

static void * kernel_stack_base();
static void kernel_bss_clear();

static void kernel_idt_load();

static void kernel_halt();

static void * module_addresses[] = {
	(void *) MODULE_SHELL_ADDRESS // Shell address
};

void * kernel_init() {	
	module_load(&endOfKernelBinary, module_addresses);

	kernel_bss_clear();

	return kernel_stack_base();
}

int kernel_main() {
	video_init();
	out_init();
	out_printf("Initializing video driver... [Done]\n");
	out_printf("Loading modules... [Done]\n");

	out_printf("Initializing serial port... ");
	serial_init();
	out_printf("[Done]\n");

	log_init();
	log("# Kernel Main\n");
	log("## Kernel's binary\n");
	log("\ttext: %h\n", (uint64_t) &text);
	log("\trodata: %h\n", (uint64_t) &rodata);
	log("\tdata: %h\n", (uint64_t) &data);
	log("\tbss: %h\n\n", (uint64_t) &bss);

	out_printf("Disabling interrupts... ");
	_interrupt_clear();
	log("\tCLI\n");
	_pic_mask((uint8_t) 0xFF); // TODO: 0xFF define
	log("\tPIC Masc set to: 0xFF\n");
	out_printf("[Done]\n");

	out_printf("Loading IDT... ");
	kernel_idt_load();
	out_printf("[Done]\n");

	out_printf("Enabling interrupts... ");
	_interrupt_set();
	log("\tSTI\n");
	_pic_mask((uint8_t) 0xFC); // TODO: 0xFC define
	log("\tPIC Masc set to: 0xFC\n\n");
	out_printf("[Done]\n");
	
	//((EntryPoint) module_addresses[MODULE_SHELL_INDEX])();

	return 0;
}

void kernel_panic(char * code, char * desc, char * source, int halt) {
	out_box_top();
	out_box_line("OOPS! Something went wrong", "");
	out_box_line("EXCEPTION CODE: #%s", code);
	out_box_line("DESCRIPTION: %s", desc);
	out_box_line("SOURCE: %s", source);
	out_box_line("HALT SYSTEM? %s", STRINGNIFY_BOOL_YESNO(halt));
	out_box_bottom();
	out_printf("\n");
	
	if(halt) {
		kernel_halt();
	}
}

static void * kernel_stack_base() {
	return (void *) (
		(uint64_t) &endOfKernel			// End of kernel address
		+ ((uint64_t) PAGE_SIZE) * 8	// The size of the stack itself, 32KiB
		- sizeof(uint64_t)				// Begin at the top of the stack
	);
}

static void kernel_bss_clear() {
	memset(&bss, 0, &endOfKernel - &bss);
}

static void kernel_idt_load() {
	idt_init();

	// Exceptions 
	_IDT_ENTRY_EXCEPTION(00);
	_IDT_ENTRY_EXCEPTION(02);
	_IDT_ENTRY_EXCEPTION(03);
	_IDT_ENTRY_EXCEPTION(04);
	_IDT_ENTRY_EXCEPTION(05);
	_IDT_ENTRY_EXCEPTION(06);
	_IDT_ENTRY_EXCEPTION(07);
	_IDT_ENTRY_EXCEPTION(08);
	_IDT_ENTRY_EXCEPTION(09);
	_IDT_ENTRY_EXCEPTION(0A);
	_IDT_ENTRY_EXCEPTION(0B);
	_IDT_ENTRY_EXCEPTION(0C);
	_IDT_ENTRY_EXCEPTION(0D);
	_IDT_ENTRY_EXCEPTION(0E);
	_IDT_ENTRY_EXCEPTION(10);
	_IDT_ENTRY_EXCEPTION(11);
	_IDT_ENTRY_EXCEPTION(12);
	_IDT_ENTRY_EXCEPTION(13);
	// ^^^ Exceptions ^^^
}

static void kernel_halt() { // TODO: Static?
	out_printf("Disabling interrupts... ");
	_interrupt_clear();
	log("\tCLI\n");
	_pic_mask((uint8_t) 0xFF); // TODO: 0xFF define
	log("\tPIC Masc set to: 0xFF\n");
	out_printf("[Done]\n");
	out_printf("System halted!");
	_halt();
}