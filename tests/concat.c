/*
 * Tests for concatenating two strings.
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("foo");
    struct CString string_b = cstring_init("barbaz");
    struct CString string_c = cstring_init("");

    cstring_concat(&string_a, string_b);

    /* string_a should be different */
    assert(string_a.length == 9);
    assert(string_a.capacity == 10);
    assert(string_a.contents != NULL);
    assert(string_a.contents[string_a.length] == '\0');

    assert(string_b.contents != NULL);
    assert(string_b.contents[string_b.length] == '\0');

    /* Append an empty string */
    cstring_concat(&string_a, string_c);
    assert(string_a.length == 9);
    assert(string_a.capacity == 10);
    assert(string_a.contents != NULL);
    assert(string_a.contents[string_a.length] == '\0');

    assert(string_c.contents != NULL);
    assert(string_c.contents[string_c.length] == '\0');

    /* Append to an empty string */
    cstring_concat(&string_c, string_a);

    assert(string_c.length == 9);
    assert(string_c.capacity == 10);
    assert(string_c.contents != NULL);
    assert(string_c.contents[string_c.length] == '\0');

    assert(string_c.contents != NULL);
    assert(string_c.contents[string_c.length] == '\0');

    cstring_free(string_a);
    cstring_free(string_b);
    cstring_free(string_c);

    return EXIT_SUCCESS;
}
