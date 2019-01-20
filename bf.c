#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ivector.h"
enum {
	END_OF_PROGRAM=-255,
	JUMP_FORWARD_TO_INVALID_ADDRESS,
	JUMP_BACK_TO_INVALID_ADDRESS,
	ILLEGAL_INSTRUCTION
};

char *bf_valid = "><+-.,[]";

int bf_step(ivector_t *program,
			char *tape,
			int pc,
			int *pointer,
			ivector_t *loop_stack){
	int tmp;
	if (pc >= program->size) return END_OF_PROGRAM;
	switch (program->data[pc]){
		case '>':
			(*pointer)++;
			break;
		case '<':
			(*pointer)--;
			break;
		case '+':
			tape[*pointer]++;
			break;
		case '-':
			tape[*pointer]--;
			break;
		case '.':
			putchar(tape[*pointer]);
			break;
		case ',':
			tmp = getchar();
			tape[*pointer] = (tmp == EOF)?0:tmp;
			break;
		case '[':
			tmp = pc;
			ivector_push(loop_stack, pc);
			if (tape[*pointer] != 0){
				break;
			}
			for (pc += 1; pc < program->size; pc++){
				if (program->data[pc] == '['){
					ivector_push(loop_stack, pc);
				}
				else if (program->data[pc] == ']' &&
					ivector_pop(loop_stack) == tmp){
					return pc + 1;
				}
			}
			return JUMP_FORWARD_TO_INVALID_ADDRESS;
		case ']':
			if (loop_stack->size == 0) return JUMP_BACK_TO_INVALID_ADDRESS;
			tmp = ivector_pop(loop_stack);
			if (tape[*pointer] == 0){
				break;
			}
			return tmp;
		default:
			return ILLEGAL_INSTRUCTION;
	}
	return pc + 1;
}

int load_program(ivector_t *program) {
	/* Codigo a completar por el alumno */
	int c, cont = 0;
	while((c = getchar()) != EOF) {
		switch (c) {
		        case '<':
						ivector_push(program, c);
						break;
				case '>':
						ivector_push(program, c);
						break;
				case '+':
						ivector_push(program, c);
						break;
				case '-':
						ivector_push(program, c);
						break;
				case '.':
						ivector_push(program, c);
						break;
				case ',':
						ivector_push(program, c);
						break;
				case '[':
						ivector_push(program, c);
						cont++;
						break;
				case ']':
						if(cont > 0) {
							ivector_push(program, c);
							cont--;
						}
						else {
							printf("Se encontro un ] sin su [ correspondiente \n");
							return (0);
						}
						break;
				case ' ':
						break;
				case '\n':
						break;
				default: 
						printf("Error de sintaxis \n");
						return (0);
		}
	}
	if(cont > 0) {
		printf("Se encontro un [ sin su ] correspondiente \n");
		return (0);
	}
	return (1);
}
