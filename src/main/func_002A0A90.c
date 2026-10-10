#include "types.h"

typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; char* longData; } SsoString;

extern int strlen(const char* s); /* strlen */
extern void String_Compare(SsoString* self, int pos, int n, const char* s, int len);

/* Assigns a C string to the string by replacing its whole contents. */
void func_002A0A90(SsoString* self, const char* s)
{
    int len = strlen(s);
    String_Compare(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, s, len);
}
