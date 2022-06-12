/*
 * Implementations of internal functions for cstring.
*/

#include "cstring.h"
#include "cstring_internal.h"

int cstring_difference(struct CString cstring_a, struct CString cstring_b) {
    liberror_is_negative(cstring_difference, cstring_a.length);
    liberror_is_negative(cstring_difference, cstring_b.length);

    if(cstring_a.length > cstring_b.length)
        return cstring_a.length - cstring_b.length;

    if(cstring_b.length > cstring_a.length)
        return cstring_b.length - cstring_a.length;

    return 0;
}
