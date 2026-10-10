#include "types.h"

/* Short/long string header: bit 0 = long form, bits 1-7 = inline length. */
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;

extern void func_001C4330(StrHdr* str, int len, int start, int arg);

/* Forwards to func_001C4330 with the string's current length and start 0. */
void func_001C4300(StrHdr* str, int arg) {
    int len;
    if (*(int*)str & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->shortLen;
    }
    func_001C4330(str, len, 0, arg);
}
