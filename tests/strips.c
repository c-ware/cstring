/*
 * Tests for stripping C-style strings from a cstring
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("foo bar baz tuna spam");
    struct CString string_b = cstring_init(" ");
    struct CString string_c = cstring_init("tuna");
    struct CString string_d = cstring_init("foo bar baz tuna spam");
    struct CString string_e = cstring_init("");

    assert(cstring_strips(&string_a, " ") == 4);
    assert(cstring_strips(&string_d, "tuna") == 1);
    assert(cstring_strips(&string_e, "tuna") == 0);

    cstring_free(string_a);
    cstring_free(string_b);
    cstring_free(string_c);
    cstring_free(string_d);
    cstring_free(string_e);

    return EXIT_SUCCESS;
}
