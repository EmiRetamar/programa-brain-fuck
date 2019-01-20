#ifndef _CVECTOR_H_
#define _CVECTOR_H_
/**
 * @file
 * Estructuras de datos y funciones que proveen un vector dinámico de ints
 */

#include <stdlib.h>

/**
 * @brief Factor de crecimiento del vector
 *
 * El vector crecerá de a `GROW_FACTOR` ints cada vez que `size > reserved`.
 */
#define GROW_FACTOR 1024

/**
 * @brief Factor de decrecimiento del vector
 *
 * Cuando una operación de borrado reduzca el tamaño del vector
 * y `reserved - size > GROW_FACTOR` se reducirá el tamaño del vector
 * a `reserved - SHRINK_FACTOR`
 */
#define SHRINK_FACTOR GROW_FACTOR / 2

/**
 * @brief Estructura que representa un vector de elementos de tipo @c int dinámico
 */
struct ivector {
	int *data; ///< Buffer de datos
	int size; ///< Tamaño usado del vector
	int reserved; ///< Tamaño alocado para el vector
};

typedef struct ivector ivector_t; ///< @see struct ivector

/**
 * @brief Crea un nuevo vector vacío
 *
 * @return Un @c ivector_t de tamaño 0
 */
ivector_t ivector_new();

/**
 * @brief Agrega un elemento al final.
 *
 * Agrega un elemento al final del vector, de ser necesario lo agranda.
 * @param vector Vector que se usará
 * @param element Nuevo int a agregar
 */
void ivector_append(ivector_t *vector, int element);

/**
 * @brief Elimina el último elemento.
 *
 * Elimina el último elemento del vector, de ser necesario lo achica.
 * @param vector El vector a reducir
 * @return El int de la posición eliminada
 */
int ivector_remove_last(ivector_t *vector);

/**
 * @brief Libera toda la memoria reservada para el vector.
 *
 * @param vector El vector a liberar
 */
void ivector_free(ivector_t *vector);

/** 
 * @brief Macro para que se parezca a una pila.
 *
 * @see ivector_append
 */
#define ivector_push(v, e) ivector_append((v), (e))
/**
 * @brief Macro para que se parezca a una pila.
 *
 * @see ivector_remove_last
 */
#define ivector_pop(v) ivector_remove_last((v))

/**
 * @brief Convierte un ivector_t a (char *)
 * Dado un ivector_t con elementos en el rango ASCII, aloca
 * un arreglo de chars, copia el contenido de ivector_t elemento
 * a elemento y trunca el arreglo de chars con \\0
 *
 * @param vector El vector desde el cuál se tomarán los datos
 * @return Un (char *) apuntando a un arreglo de chars alocado
 * con malloc() (recordar liberar este arreglo con free())
 */
char *ivector_as_string(ivector_t vector);

#endif
