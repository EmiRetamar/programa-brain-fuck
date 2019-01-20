#include "ivector.h"
#include <assert.h>

ivector_t ivector_new(){
	ivector_t n;
	n.size = n.reserved = 0;
	n.data = NULL;
	return n;
}
#include <stdio.h>
char *ivector_as_string(ivector_t v){
	int i;
	char *s = malloc((v.size + 1) * sizeof(char));
	for (i = 0; i < v.size; i++){
		s[i] = v.data[i];
	}
	s[i] = 0;
	return s;
}

void ivector_append(ivector_t *v, int e){
	v->size++;
	if (v->size > v->reserved){
		v->reserved += GROW_FACTOR;
		v->data = realloc(v->data, v->reserved * sizeof(int));
	}
	v->data[v->size-1] = e;
}

int ivector_remove_last(ivector_t *v){
	int retval;
	assert(SHRINK_FACTOR <= GROW_FACTOR);
	v->size--;
	retval = v->data[v->size];
	if (v->reserved - v->size > GROW_FACTOR){
		v->reserved -= SHRINK_FACTOR;
		v->data = realloc(v->data, v->reserved * sizeof(int));
	}
	return retval;
}

void ivector_free(ivector_t *v){
	free(v->data);
	v->size = v->reserved = 0;
}

