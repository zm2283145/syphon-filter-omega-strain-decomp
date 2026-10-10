#include "types.h"

/* Short/long string header: bit 0 = long form, bits 1-7 = inline length. */
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;

extern int strlen(const char* s); /* strlen */
extern void String_Compare(StrHdr* str, int pos, int count, const char* src, int srcLen);

/* String assign from a C string: replaces the whole contents with cstr. */
void String_AssignCStr(StrHdr* str, const char* cstr) {
    int srcLen = strlen(cstr);
    int len;
    if (*(int*)str & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->shortLen;
    }
    String_Compare(str, 0, len, cstr, srcLen);
}
