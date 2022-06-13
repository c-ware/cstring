/*
 * Tests for finding a string in a substring.
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("foo bar baz tuna spam");
    struct CString string_b = cstring_init("baz");
    struct CString string_c = cstring_init("");

    assert(cstring_find(string_a, string_b) == 8);
    assert(cstring_find(string_a, string_c) == 0);
    assert(cstring_find(string_c, string_b) == CSTRING_NOT_FOUND);
    assert(cstring_find(string_b, string_c) == 0);
    assert(cstring_find(string_a, string_a) == 0);
    assert(cstring_find(string_b, string_a) == CSTRING_NOT_FOUND);

    cstring_free(string_a);
    cstring_free(string_b);
    cstring_free(string_c);

    return EXIT_SUCCESS;
}
