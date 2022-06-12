/*
 * Tests for concatenating a cstring with a string literal.
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("foo");

    /* Add a regular string */
    cstring_concats(&string_a, "bar");
    assert(strcmp(cstring_string(string_a), "foobar") == 0);
    assert(string_a.contents != NULL);
    assert(string_a.length == 6);
    assert(string_a.capacity == 7);

    /* Add an empty string. Nothing should have changed. */
    cstring_concats(&string_a, "");
    assert(strcmp(cstring_string(string_a), "foobar") == 0);
    assert(string_a.contents != NULL);
    assert(string_a.length == 6);
    assert(string_a.capacity == 7);

    /* Add a much larger string */
    cstring_concats(&string_a, ": Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus");
    assert(strcmp(cstring_string(string_a), "foobar: Lorem ipsum dolor sit amet, consectetur adipiscing elit. Vivamus") == 0);
    assert(string_a.contents != NULL);
    assert(string_a.length == 72);
    assert(string_a.capacity == 73);

    cstring_free(string_a);

    return EXIT_SUCCESS;
}
