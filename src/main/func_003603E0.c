#include "types.h"

/* Short/long string header: bit 0 = long form, bits 1-7 = inline length. */
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;

/* Empty allocator object passed by value (its byte is never initialized). */
typedef struct Alloc {
    char unused;
    char pad[3];
} Alloc;

extern void String_Replace(StrHdr* str, int start, int len, int a, int b, char alloc);

/* Forwards the whole string (start 0, current length) to String_Replace. */
void func_003603E0(StrHdr* str, int a, int b) {
    volatile Alloc alloc;
    int len;
    if (*(int*)str & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->shortLen;
    }
    String_Replace(str, 0, len, a, b, alloc.unused);
}
