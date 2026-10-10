#include "types.h"

typedef struct String3 {
    char* begin;
    char* end;
    char* cap;
} String3;

extern int strlen(const char* s); /* strlen */
extern void String_Reserve(String3* str, int len);
extern void String_Replace(String3* str, int a, int b, const char* first, const char* last, signed char tag);

/* String constructor from a C string. */
String3* func_002A7070(String3* str, const char* s) {
    volatile signed char tag[4]; /* empty tag argument, never initialized */
    int len;
    str->begin = 0;
    str->end = 0;
    str->cap = 0;
    len = strlen(s);
    String_Reserve(str, len);
    String_Replace(str, 0, 0, s, s + len, tag[0]);
    return str;
}
