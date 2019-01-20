#include <stdio.h>
#include "bf.h"

int main(){
	ivector_t program = ivector_new();
	ivector_t loop_stack;
	char *tape = calloc(30000, sizeof(char));
	int pc = 0;
	int pointer = 0;
	if (!load_program(&program)){
		// Error al leer el programa
		ivector_free(&program);
		exit(2);
	}
	loop_stack = ivector_new();
	do {
		pc = bf_step(&program, tape, pc, &pointer, &loop_stack);
	} while (pc >= 0);
	ivector_free(&program);
	ivector_free(&loop_stack);
	return (pc >= 0);
}
