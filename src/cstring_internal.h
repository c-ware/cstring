/*
 * Internal functions used by the cstring operations. Exposed mainly
 * for the purposes of writing tests for internal behavior.
*/

#ifndef CWARE_CSTRING_INTERNAL_H
#define CWARE_CSTRING_INTERNAL_H

#include "cstring.h"

/*
 * @docgen: function
 * @brief: calculate the difference in length between two strings
 * @name: cstring_difference
 *
 * @include: cstring_internal.h
 *
 * @description
 * @Calculate the difference in length between two strings. Used internally
 * @for knowing how much to resize a string during an addition operation.
 * @The order of the strings does not matter-- the largest length is chosen
 * @to be subtracted from.
 * @description
 *
 * @example
 * @#include <stdio.h>
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo");
 * @    struct CString string_b = cstring_init("bar");
 * @
 * @    printf("Length difference: %i\\n", cstring_difference(string_a, string_b));
 * @
 * @    cstring_free(string_a);
 * @    cstring_free(string_b);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @notes
 * @This function is meant for internal use only. Please refrain from using
 * @it in your production code directly.
 * @notes
 *
 * @error: cstring_a.length is NULL
 * @error: cstring_b.length is NULL
 *
 * @param cstring_a: the first cstring
 * @type: struct CString
 *
 * @param cstring_b: the second cstring
 * @type: struct CString
 *
 * @return: the difference in length between the two strings
 * @type: int
*/
int cstring_difference(struct CString cstring_a, struct CString cstring_b);

#endif
