/*
 * Tests for determining if a cstring ends with a C-style string
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("foo bar baz tuna spam");
    struct CString string_b = cstring_init("foo");
    struct CString string_c = cstring_init("");
    struct CString string_d = cstring_init("spam");

    assert(cstring_endswiths(string_a, "spam") == 1);
    assert(cstring_endswiths(string_a, "") == 1);
    assert(cstring_endswiths(string_a, "") == 1);
    assert(cstring_endswiths(string_a, "foo") == 0);
    assert(cstring_endswiths(string_c, "foo bar baz tuna spam") == 0);
    assert(cstring_endswiths(string_c, "foo") == 0);
    assert(cstring_endswiths(string_c, "spam") == 0);

    cstring_free(string_a);
    cstring_free(string_b);
    cstring_free(string_c);
    cstring_free(string_d);

    return EXIT_SUCCESS;
}
