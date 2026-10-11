#include "types.h"
typedef struct StrHdr {
    unsigned isLong : 1;
    unsigned shortLen : 7;
    int longLen;
} StrHdr;
extern void String_Replace(StrHdr* str, int pos, int count, const char* first, const char* last, char alloc);
void func_002A0020(StrHdr* str, const char* first, const char* last)
{
    volatile char alloc[4];
    int len;
    if (*(int*)str & 1) {
        len = str->longLen;
    } else {
        len = (unsigned char)str->shortLen;
    }
    String_Replace(str, 0, len, first, last, alloc[0]);
}