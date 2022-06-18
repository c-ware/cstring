/*
 * Test integration with CArray
*/

#include "common.h"

void add_cstring(struct CStrings *array, const char *string) {
    struct CString new_string = cstring_init(string);

    carray_append(array, new_string, CSTRING);
}

int main(void) {
    struct CStrings *string_array = carray_init(string_array, CSTRING);

    add_cstring(string_array, "foo");
    assert(strcmp(string_array->contents[0].contents, "foo") == 0);

    add_cstring(string_array, "baz");
    assert(strcmp(string_array->contents[0].contents, "foo") == 0);
    assert(strcmp(string_array->contents[1].contents, "baz") == 0);

    add_cstring(string_array, "tuna");
    assert(strcmp(string_array->contents[0].contents, "foo") == 0);
    assert(strcmp(string_array->contents[1].contents, "baz") == 0);
    assert(strcmp(string_array->contents[2].contents, "tuna") == 0);

    carray_free(string_array, CSTRING);

    return EXIT_SUCCESS;
}
