#include "types.h"

typedef struct SsoString {
    union {
        unsigned int word;          /* 0x00, bit 0 = long mode */
        struct {
            unsigned char isLong : 1;
            unsigned char shortLen : 7;
        } bits;
    } mode;
    int longLen;                /* 0x04 */
    char* longData;             /* 0x08 */
} SsoString;

extern void String_Replace(SsoString* str, int pos, int count, const char* first, const char* last, signed char tag);

/* Assigns the range [first, last) to the string, replacing its whole contents. */
void func_0028B270(SsoString* str, const char* first, const char* last) {
    volatile signed char tag[4]; /* empty tag argument, never initialized */
    int len;
    if (str->mode.word & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->mode.bits.shortLen;
    }
    String_Replace(str, 0, len, first, last, tag[0]);
}
