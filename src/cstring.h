/*
 * @docgen: project
 * @brief: ansi c compliant dynamically allocated string
 * @name: cstring
 *
 * @embed structure: CString
 *
 * @description
 * @An ANSI C compliant dynamically allocated string implementation with a
 * @focus on efficient use of memory. One of the main design choices of cstring 
 * @is to put emphesis on the reuse of existing string objects to reduce overall
 * @memory usage.
 * @
 * @Another important design choice of cstring is to provide some degree of
 * @interopability between a cstring, and a C-style string. To achieve this,
 * @cstrings are NUL terminated, while also having a length field for any
 * @situations where the programmer may want length-prefixed strings, such as
 * @constant time length operations, and the need for the NUL byte in the body
 * @of the string.
 * @description
*/

#ifndef CWARE_CSTRING_H
#define CWARE_CSTRING_H

#include "liberror/liberror.h"

/*
 * @docgen: structure
 * @brief: a dynamically allocated string
 * @name: CString
 *
 * @field length: the length of the string
 * @type: int
 *
 * @field capacity: the physical capacity of the string
 * @type: int
 *
 * @field contents: the characters in the string
 * @type: char *
*/
struct CString {
    int length;
    int capacity;
    char *contents;
};


/*
 * @docgen: function
 * @brief: initialize a new cstring
 * @name: cstring_init
 *
 * @include: cstring.h
 *
 * @description
 * @Initialize a new cstring with a base string in the body of the cstring.
 * @If an empty cstring is desired, then base should be an empty string.
 * @description
 *
 * @example
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString new_string = cstring_init("basic body");
 * @
 * @    cstring_free(new_string);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: base is NULL
 *
 * @param base: the base string to use as the body
 * @type: const char *
 *
 * @return: a new cstring
 * @type: struct CString
 *
 * @reference: cware(cware)
 * @reference: cstring(cware)
*/
struct CString cstring_init(const char *base);

/*
 * @docgen: function
 * @brief: release a cstring from memory
 * @name: cstring_free
 *
 * @include: cstring.h
 *
 * @description
 * @Releases a cstring from memory. Since the cstring structure is most
 * @likely going to be on the stack, only the body of the string must be
 * @released.
 * @description
 *
 * @example
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString new_string = cstring_init("basic body");
 * @
 * @    cstring_free(new_string);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring.contents is NULL
 *
 * @param cstring: the cstring to free
 * @type: struct CString
 *
 * @reference: cware(cware)
 * @reference: cstring(cware)
*/
void cstring_free(struct CString cstring);

/*
 * @docgen: function
 * @brief: reset a string to be reused
 * @name: cstring_reset
 *
 * @include: cstring.h
 *
 * @description
 * @Reset the length of the string and NUL terminate the beginning of it
 * @to 'reset' the string. Note that this does not actually erase or reset
 * @the physical contents of the buffers-- only makes the accessible parts
 * @of the buffer seem to be reset.
 * @description
 *
 * @example
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo");
 * @    struct CString string_b = cstring_init("bar");
 * @
 * @    // Concatenate, then reset string_a
 * @    cstring_concat(string_a, string_b);
 * @    cstring_reset(&string_a);
 * @
 * @    cstring_free(string_a);
 * @    cstring_free(string_b);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring is NULL
 * @error: cstring->contents NULL
 * @error: cstring->length is negative
 *
 * @param cstring: the cstring to reset
 * @type: struct CString
*/
void cstring_reset(struct CString *cstring);

/*
 * @docgen: function
 * @brief: concatenate two strings
 * @name: cstring_concat
 *
 * @include: cstring.h
 * 
 * @description
 * @Concatenates string_a into string_b, modifying string_a in-place.
 * @description
 *
 * @example
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo");
 * @    struct CString string_b = cstring_init("bar");
 * @
 * @    cstring_concat(string_a, string_b);
 * @
 * @    cstring_free(string_a);
 * @    cstring_free(string_b);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring_a is NULL
 * @error: cstring_a->contents is NULL
 * @error: cstring_b.contents is NULL
 * @error: cstring_a->length is negative
 * @error: cstring_b.length is negative
 * @error: cstring_a->capacity is negative
 * @error: cstring_b.capacity is negative
 *
 * @param cstring_a: the cstring to write into
 * @type: struct CString *
 *
 * @param cstring_b: the cstring to write
 * @type: struct CString
*/
void cstring_concat(struct CString *cstring_a, struct CString cstring_b);










/*
 * @docgen: function
 * @brief: load a file into a cstring
 * @name: cstring_loadf
 *
 * @include: cstring.h
 *
 * @description
 * @Loads the contents of a file into a NUL-terminated cstring.
 * @description
 *
 * @example
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    // Load the stdin into a file
 * @    struct CString string_a = cstring_loadf(stdin);
 * @
 * @    cstring_free(string_b);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: file is NULL
 *
 * @param file: the file to load
 * @type: FILE *
 *
 * @return: a new cstring
 * @type: struct CString
*/
struct CString cstring_loadf(FILE *file);











#endif
