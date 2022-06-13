/*
 * Tests for determining if a cstring starts with a C-style string
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("foo bar baz tuna spam");
    struct CString string_c = cstring_init("");
    struct CString string_d = cstring_init("foo");

    assert(cstring_startswiths(string_a, "baz") == 0);
    assert(cstring_startswiths(string_a, "foo") == 1);
    assert(cstring_startswiths(string_c, "foo") == 0);
    assert(cstring_startswiths(string_d, "") == 1);
    assert(cstring_startswiths(string_d, "baz") == 0);

    cstring_free(string_a);
    cstring_free(string_c);
    cstring_free(string_d);

    return EXIT_SUCCESS;
}
