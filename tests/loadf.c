/*
 * Test loading data from a file.
*/

#include "common.h"

void test_file(const char *matching_string, const char *file_path) {
    FILE *file = fopen(file_path, "r");
    struct CString file_string = cstring_loadf(file);

    assert(strcmp(file_string.contents, matching_string) == 0);

    fclose(file);
    cstring_free(file_string);
}

int main(void) {
    test_file(bytes_1024, GET_TEST_ASSET("1024_bytes.txt"));
    test_file(bytes_2048, GET_TEST_ASSET("2048_bytes.txt"));
    test_file(bytes_4096, GET_TEST_ASSET("4096_bytes.txt"));

    return 0;
}
