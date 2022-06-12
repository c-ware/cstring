/*
 * File implementing main operations for cstring.
*/

#include <stdlib.h>
#include <string.h>

#include "cstring.h"
#include "cstring_internal.h"

/* Memory focused operations */

struct CString cstring_init(const char *body) {
    int body_length = 0;
    struct CString cstring;

    liberror_is_null(cstring_init, body);

    body_length = strlen(body);
    cstring.length = body_length;
    cstring.capacity = body_length + 1;
    cstring.contents = malloc(body_length + 1);

    strncat(cstring.contents, body, body_length);
    cstring.contents[body_length] = '\0';

    return cstring;
}

void cstring_free(struct CString cstring) {
    liberror_is_null(cstring_free, cstring.contents);

    free(cstring.contents);
}

void cstring_reset(struct CString *cstring) {
    liberror_is_null(cstring_reset, cstring);
    liberror_is_null(cstring_reset, cstring->contents);
    liberror_is_negative(cstring_reset, cstring->length);

    cstring->length = 0;
    cstring->contents[0] = '\0';
}

/* Addition based operations */
void cstring_concat(struct CString *cstring_a, struct CString cstring_b) {
    int index = 0;
    int new_length = 0;

    liberror_is_null(cstring_concat, cstring_a);
    liberror_is_null(cstring_concat, cstring_a->contents);
    liberror_is_null(cstring_concat, cstring_b.contents);

    liberror_is_negative(cstring_concat, cstring_a->length);
    liberror_is_negative(cstring_concat, cstring_b.length);

    liberror_is_negative(cstring_concat, cstring_a->capacity);
    liberror_is_negative(cstring_concat, cstring_b.capacity);

    /* Do not resize cstring_a if no change will be made */
    if(cstring_b.length == 0)
        return;

    /* Resize buffer first */
    new_length = cstring_a->length + cstring_b.length;
    cstring_a->contents = realloc(cstring_a->contents, new_length + 1);

    for(index = 0; index < cstring_b.length; index++) {
        cstring_a->contents[cstring_a->length + index] = cstring_b.contents[index];
    }

    /* Finalize cstring_a */
    cstring_a->contents[cstring_a->length + index] = '\0';
    cstring_a->length = new_length;
    cstring_a->capacity = new_length + 1;
}

/* Less general purpose operations */
struct CString cstring_loadf(FILE *file) {
    int length = 0;
    struct CString cstring;

    liberror_is_null(cstring_loadf, file);

    fseek(file, 0, SEEK_END);
    length = ftell(file);

    /* Prepare the buffer and cstring */
    cstring.contents = malloc(sizeof(char) * (length + 1));
    cstring.contents[length + 1] = '\0';
    cstring.length = length;
    cstring.capacity = length + 1;

    /* Load the file */
    rewind(file);
    fread(cstring.contents, 1, length, file);
    
    return cstring;
}
