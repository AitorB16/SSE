#ifndef _literal
#define _literal

#include "misc.h"
#
/**
* Structure to contain a literal.
* This is a bijective union between a string & a number.
*
* @see get_conf.c
* @see print_results.c
*/
typedef struct literal_t {
	int value;
	char * name;
} literal_t;

#define LITERAL_END { 0, NULL } ///< This must be the last literal in an array.

// Some declarations
bool_t literal_value(literal_t * literal, char *  name, int * value);

bool_t literal_name (literal_t * literal, char ** name, int   value);

#endif
