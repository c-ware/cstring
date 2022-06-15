/*
 * Tests for slicing a component of the C-string
*/

#include "common.h"

int main(void) {
    struct CString slice;
    struct CString string_a = cstring_init("foo bar baz tuna spam");

    slice = cstring_slice(string_a, 0, 3);
    assert(slice.contents == string_a.contents);
    assert(slice.length == 3);
    assert(slice.capacity == 3);
    assert(slice.contents[0] == 'f');
    assert(slice.contents[1] == 'o');
    assert(slice.contents[2] == 'o');

    slice = cstring_slice(string_a, 4, 7);
    assert(slice.contents != string_a.contents);
    assert(slice.length == 3);
    assert(slice.capacity == 3);
    assert(slice.contents[0] == 'b');
    assert(slice.contents[1] == 'a');
    assert(slice.contents[2] == 'r');

    /* Essentially make a copy of the base string. */
    slice = cstring_slice(string_a, 0, string_a.length);
    assert(slice.contents == string_a.contents);
    assert(slice.length == 21);
    assert(slice.capacity == 21);
    assert(slice.contents[0] == 'f');
    assert(slice.contents[1] == 'o');
    assert(slice.contents[2] == 'o');
    assert(slice.contents[3] == ' ');
    assert(slice.contents[4] == 'b');
    assert(slice.contents[5] == 'a');
    assert(slice.contents[6] == 'r');
    assert(slice.contents[7] == ' ');
    assert(slice.contents[8] == 'b');
    assert(slice.contents[9] == 'a');
    assert(slice.contents[10] == 'z');
    assert(slice.contents[11] == ' ');
    assert(slice.contents[12] == 't');
    assert(slice.contents[13] == 'u');
    assert(slice.contents[14] == 'n');
    assert(slice.contents[15] == 'a');
    assert(slice.contents[16] == ' ');
    assert(slice.contents[17] == 's');
    assert(slice.contents[18] == 'p');
    assert(slice.contents[19] == 'a');
    assert(slice.contents[20] == 'm');
    

    cstring_free(string_a);

    return EXIT_SUCCESS;
}
