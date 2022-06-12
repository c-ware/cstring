/*
 * Tests for concatenating two strings.
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("foo");
    struct CString string_b = cstring_init("barbaz");
    struct CString string_c = cstring_init("");
    void *old_buffer = NULL;

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

    /* What if we try concatenating to a reset string?
     * Make sure we verify the old buffers are the same. If
     * they are not, a resize happened. */
    cstring_reset(&string_a);
    cstring_concat(&string_a, string_b);
    old_buffer = cstring_string(string_a);

    assert(string_a.length == 6);
    assert(string_a.capacity == 7);
    assert(string_a.contents != NULL);
    assert(string_a.contents[string_a.length] == '\0');
    assert(old_buffer == cstring_string(string_a));

    cstring_free(string_a);
    cstring_free(string_b);
    cstring_free(string_c);

    return EXIT_SUCCESS;
}
