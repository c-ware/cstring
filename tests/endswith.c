/*
 * Tests for determining if a cstring ends with another CString
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("foo bar baz tuna spam");
    struct CString string_b = cstring_init("foo");
    struct CString string_c = cstring_init("");
    struct CString string_d = cstring_init("spam");

    assert(cstring_endswith(string_a, string_d) == 1);
    assert(cstring_endswith(string_a, string_c) == 1);
    assert(cstring_endswith(string_a, string_c) == 1);
    assert(cstring_endswith(string_a, string_b) == 0);
    assert(cstring_endswith(string_c, string_a) == 0);
    assert(cstring_endswith(string_c, string_b) == 0);
    assert(cstring_endswith(string_c, string_d) == 0);

    cstring_free(string_a);
    cstring_free(string_b);
    cstring_free(string_c);
    cstring_free(string_d);

    return EXIT_SUCCESS;
}
