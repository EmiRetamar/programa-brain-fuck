#ifndef _BF_H_
#define _BF_H_
/** @file
 * Funciones para interpretar BF
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ivector.h"
/**
 * @brief Códigos de error
 */
enum {
	END_OF_PROGRAM=-255,
	JUMP_FORWARD_TO_INVALID_ADDRESS,
	JUMP_BACK_TO_INVALID_ADDRESS,
	ILLEGAL_INSTRUCTION
};

/**
 * @brief Arreglo de símbolos válidos en BF
 */
extern char *bf_valid;

/**
 * @brief Avanza una instrucción
 *
 * Ejecuta una instrucción de bf ajustando todo el entorno de ejecución.
 * @param program Un `ivector_t` con el programa completo en bf.
 * @param tape La *cinta* con los datos del programa.
 * @param pc Contador de programa, es el indice de la instrucción
 *  actual dentro de `program->data[]`.
 * @param pointer Indice a la posición actual dentro de la *cinta* de datos.
 * @param loop_stack Nivel de anidado dentro de `[` y `]`, incialmente vacío.
 */
int bf_step(ivector_t *program, char *tape, int pc, int *pointer, ivector_t *loop_stack);

/**
 * @brief Carga un programa en bf
 *
 * Carga un programa en bf ingresado por teclado.
 * @param program Un `ivector_t` previamente inicializado donde se
 * cargará el programa en bf leído, sin incluir blancos ni `\n`.
 */
int load_program(ivector_t *program);

#endif
