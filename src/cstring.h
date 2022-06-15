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

#define CSTRING_NOT_FOUND   -1

/*
 * @docgen: macro_function
 * @brief: get the string from the cstring
 * @name: cstring_string
 *
 * @param cstring: the cstring to get the string component of
*/
#define cstring_string(cstring) \
    (cstring).contents

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
 * @brief: concatenate a c-style string to a cstring
 * @name: cstring_concats
 *
 * @include: cstring.h
 *
 * @description
 * @Concatenate a C-style string onto a cstring.
 * @description
 *
 * @example
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo");
 * @
 * @    cstring_concats(string_a, "bar");
 * @
 * @    cstring_free(string_a);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring is NULL
 * @error: string is NULL
 *
 * @param cstring: the cstring to write to
 * @type: struct CString *
 *
 * @param string: the string to concatenate
 * @type: const char *
*/
void cstring_concats(struct CString *cstring, const char *string);

/*
 * @docgen: function
 * @brief: find a cstring inside of another cstring
 * @name: cstring_find
 *
 * @include: cstring.h
 *
 * @description
 * @Determine the location of a needle in a haystack.
 * @description
 *
 * @example
 * @#include <stdio.h>
 * @
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo bar baz");
 * @    struct CString string_b = cstring_init("bar");
 * @
 * @    printf("Location of 'bar': %i\n", cstring_find(string_a, string_b));
 * @
 * @    cstring_free(string_a);
 * @    cstring_free(string_b);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: haystack.contents is NULL
 * @error: needle.contents is NULL
 * @error: haystack.length is negative
 * @error: needle.length is negative
 *
 * @param haystack: the cstring to search through
 * @type: struct CString
 *
 * @param needle: the cstring to find in the haystack
 * @type: struct CString
 *
 * @return: the location of first character of needle, or CSTRING_NOT_FOUND
 * @type: int
*/
int cstring_find(struct CString haystack, struct CString needle);

/*
 * @docgen: function
 * @brief: find a c-style string inside of a cstring
 * @name: cstring_finds
 *
 * @include: cstring.h
 *
 * @description
 * @Determine the location of a needle in a haystack, where the needle is a
 * @C-style string as opposed to a CString, and the haystack is a CString.
 * @description
 *
 * @example
 * @#include <stdio.h>
 * @
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo bar baz");
 * @
 * @    printf("Location of 'bar': %i\n", cstring_finds(string_a, "bar"));
 * @
 * @    cstring_free(string_a);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: haystack.contents is NULL
 * @error: haystack.length is negative
 * @error: needle is NULL
 *
 * @param haystack: the cstring to search through
 * @type: struct CString
 *
 * @param needle: the c-style string to find in the haystack
 * @type: const char *
 *
 * @return: the location of first character of needle, or CSTRING_NOT_FOUND
 * @type: int
*/
int cstring_finds(struct CString haystack, const char *needle);

/*
 * @docgen: function
 * @brief: determine if a cstring starts with another cstring
 * @name: cstring_startswith
 *
 * @include: cstring.h
 *
 * @description
 * @Determine if a CString starts with another CString. In other words, is
 * @a CString the prefix of another CString.
 * @description
 *
 * @example
 * @#include <stdio.h>
 * @
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo bar baz");
 * @    struct CString string_b = cstring_init("foo");
 * @
 * @    if(cstring_startswith(string_a, string_b) == 1)
 * @        printf("%s", "string_a starts with string_b\n");
 * @    else
 * @        printf("%s", "string_a does not start with string_b\n");
 * @
 * @    cstring_free(string_a);
 * @    cstring_free(string_b);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring.contents is NULL
 * @error: check.contents is NULL
 * @error: cstring.length is negative
 * @error: check.length is negative
 *
 * @param cstring: the cstring to check
 * @type: struct CString
 *
 * @param check: the cstring to check for
 * @type: struct CString
 *
 * @return: 1 if cstring starts with check, 0 if it does not
 * @type: int
*/
int cstring_startswith(struct CString cstring, struct CString check);

/*
 * @docgen: function
 * @brief: determine if a cstring starts with a c-style string
 * @name: cstring_startswiths
 *
 * @include: cstring.h
 *
 * @description
 * @Determine if a CString starts with a C-style string. In other words, is
 * @a C-style string the prefix of another CString.
 * @description
 *
 * @example
 * @#include <stdio.h>
 * @
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo bar baz");
 * @
 * @    if(cstring_startswiths(string_a, "foo") == 1)
 * @        printf("%s", "string_a starts with 'foo'\n");
 * @    else
 * @        printf("%s", "string_a does not start with 'foo'\n");
 * @
 * @    cstring_free(string_a);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring.contents is NULL
 * @error: check is NULL
 * @error: cstring.length is negative
 *
 * @param cstring: the cstring to check
 * @type: struct CString
 *
 * @param check: the c-style string to check for
 * @type: const char *
 *
 * @return: 1 if cstring starts with check, 0 if it does not
 * @type: int
*/
int cstring_startswiths(struct CString cstring, const char *check);

/*
 * @docgen: function
 * @brief: determine if a cstring ends with another cstring
 * @name: cstring_endswith
 *
 * @include: cstring.h
 *
 * @description
 * @Determine if a CString ends with another CString.
 * @description
 *
 * @example
 * @#include <stdio.h>
 * @
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo bar baz");
 * @    struct CString string_b = cstring_init("baz");
 * @
 * @    if(cstring_endswith(string_a, string_b) == 1)
 * @        printf("%s", "string_a ends with string_b\n");
 * @    else
 * @        printf("%s", "string_a does not end with string_b\n");
 * @
 * @    cstring_free(string_a);
 * @    cstring_free(string_b);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring.contents is NULL
 * @error: check.contents is NULL
 * @error: cstring.length is negative
 * @error: check.length is negative
 *
 * @param cstring: the cstring to check
 * @type: struct CString
 *
 * @param check: the cstring to check for
 * @type: struct CString
 *
 * @return: 1 if cstring ends with check, 0 if it does not
 * @type: int
*/
int cstring_endswith(struct CString cstring, struct CString check);

/*
 * @docgen: function
 * @brief: determine if a cstring ends with a C-style string
 * @name: cstring_endswiths
 *
 * @include: cstring.h
 *
 * @description
 * @Determine if a CString ends with a C-style string
 * @description
 *
 * @example
 * @#include <stdio.h>
 * @
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo bar baz");
 * @
 * @    if(cstring_endswiths(string_a, "baz") == 1)
 * @        printf("%s", "string_a ends with 'baz'\n");
 * @    else
 * @        printf("%s", "string_a does not end with 'baz'\n");
 * @
 * @    cstring_free(string_a);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring.contents is NULL
 * @error: check is NULL
 * @error: cstring.length is negative
 *
 * @param cstring: the cstring to check
 * @type: struct CString
 *
 * @param check: the c-style to check for
 * @type: const char *
 *
 * @return: 1 if cstring ends with check, 0 if it does not
 * @type: int
*/
int cstring_endswiths(struct CString cstring, const char *check);

/*
 * @docgen: function
 * @brief: strip all occurrences of a cstring from another cstring
 * @name: cstring_strip
 *
 * @include: cstring.h
 *
 * @description
 * @Remove all occurrences of a cstring from another cstring.
 * @This is an in-place operation, and thus will modify the
 * @cstring.
 * @description
 *
 * @example
 * @#include <stdio.h>
 * @
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo bar baz");
 * @    struct CString string_b = cstring_init(" ");
 * @
 * @    // Strip all occurrences of a space from the string
 * @    printf("Removed %i occurrences of ' '\n", cstring_split(&string_a, string_b));
 * @
 * @    cstring_free(string_a);
 * @    cstring_free(string_b);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring is NULL
 * @error: cstring->contents is NULL
 * @error: target.contents is NULL
 * @error: cstring->length is negative
 * @error: target.length is negative
 *
 * @param cstring: the cstring to strip from
 * @type: struct CString *
 *
 * @param target: the cstring to remove from cstring
 * @type: struct CString
 *
 * @return: the number of strips performed
 * @type: int
*/
int cstring_strip(struct CString *cstring, struct CString target);

/*
 * @docgen: function
 * @brief: strip all occurrences of a c-style string from a cstring
 * @name: cstring_strips
 *
 * @include: cstring.h
 *
 * @description
 * @Remove all occurrences of a C-style string from a cstring. This
 * @is an in-place operation, and thus will modify the CString.
 * @description
 *
 * @example
 * @#include <stdio.h>
 * @
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    struct CString string_a = cstring_init("foo bar baz");
 * @
 * @    // Strip all occurrences of a space from the string
 * @    printf("Removed %i occurrences of ' '\n", cstring_strips(&string_a, " "));
 * @
 * @    cstring_free(string_a);
 * @
 * @    return 0;
 * @}
 * @example
 *
 * @error: cstring is NULL
 * @error: cstring->contents is NULL
 * @error: target.contents is NULL
 * @error: cstring->length is negative
 * @error: target.length is negative
 *
 * @param cstring: the cstring to strip from
 * @type: struct CString *
 *
 * @param target: the cstring to remove from cstring
 * @type: struct CString
 *
 * @return: the number of strips performed
 * @type: int
*/
int cstring_strips(struct CString *cstring, const char *target);

/*
 * @docgen: function
 * @brief: load a file into a cstring
 * @name: cstring_loadf
 *
 * @include: cstring.h
 *
 * @description
 * @Loads the contents of a file into a NUL-terminated cstring. Do note, that
 * @this function will NOT work on streams. So, this will not work on stdin,
 * @for example.
 * @description
 *
 * @example
 * @#include "cstring.h"
 * @
 * @int main(void) {
 * @    // Load a file into a string
 * @    struct CString string_a = cstring_loadf("./file.txt");
 * @
 * @    cstring_free(string_a);
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
