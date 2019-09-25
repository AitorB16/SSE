#include "literal.h"
#include "misc.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
* Searches for a string in a literal array.
*
* This function takes an array of literals and finds the value corresponding to a string.
*
* @param l array of literals.
* @param name the string we are searching for.
* @param value the corresponding value for the string is returned here.
* @return if 'name' is in 'l' TRUE, else FALSE.
* @see get_conf.c
*/
bool_t literal_value(literal_t * l, char * name, int * value)
{
	while(l->name) {
		if(!strncmp(name, l->name, strlen(name))) {
			*value = l->value;
			return TRUE;
		}
		l += 1;
	}
	return FALSE;
}

/**
* Searches for a value in a literal array.
*
* This function takes an array of literals and finds the string corresponding to a value.
*
* @param l an array of literals.
* @param name the corresponding string is returned here.
* @param value the value we are searching for.
* @return if 'value' is in 'l' TRUE, else FALSE.
* @see print_results.c
*/
bool_t literal_name(literal_t * l, char ** name, int value)
{
	while(l->name) {
		if(value == l->value) {
			*name = l->name;
			return TRUE;
		}
		l += 1;
	}
	return FALSE;
}
