/*
 * Tests for finding a C-style string in a cstring.
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("foo bar baz tuna spam");
    struct CString string_b = cstring_init("baz");
    struct CString string_c = cstring_init("");

    assert(cstring_finds(string_a, "baz") == 8);
    assert(cstring_finds(string_a, "") == 0);
    assert(cstring_finds(string_c, "baz") == CSTRING_NOT_FOUND);
    assert(cstring_finds(string_b, "") == 0);
    assert(cstring_finds(string_a, "foo bar baz tuna spam") == 0);
    assert(cstring_finds(string_b, "foo bar baz tuna spam") == CSTRING_NOT_FOUND);

    cstring_free(string_a);
    cstring_free(string_b);
    cstring_free(string_c);

    return EXIT_SUCCESS;
}
