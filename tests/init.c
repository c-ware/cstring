/*
 * Test initialization of a cstring.
*/

#include "common.h"

int main(void) {
    struct CString string_a = cstring_init("base body");
    struct CString string_b = cstring_init("");

    assert(string_a.contents != NULL);
    assert(string_a.length == strlen("base body"));
    assert(string_a.capacity == strlen("base body") + 1);
    assert(strcmp(string_a.contents, "base body") == 0);

    assert(string_b.contents != NULL);
    assert(string_b.length == strlen(""));
    assert(string_b.capacity == strlen("") + 1);
    assert(strcmp(string_b.contents, "") == 0);

    cstring_free(string_a);
    cstring_free(string_b);

    return EXIT_SUCCESS;
}
