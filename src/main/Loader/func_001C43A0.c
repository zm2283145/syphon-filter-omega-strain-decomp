#include "types.h"

typedef struct { unsigned char isLong : 1; unsigned char len : 7; } ShortHdr;
typedef struct { union { unsigned int word; ShortHdr s; } hdr; int longLen; char* longData; } SsoString;

extern int strlen(const char* s); /* strlen */
extern int String_Compare(SsoString* self, int pos, int n, const char* s, int len);

/* Compare the entire string with a C string; retain the legacy symbol name. */
int String_AssignCStr_1C43A0(SsoString* self, const char* s)
{
    int len = strlen(s);
    return String_Compare(self, 0, (self->hdr.word & 1) ? self->longLen : (unsigned char)self->hdr.s.len, s, len);
}
