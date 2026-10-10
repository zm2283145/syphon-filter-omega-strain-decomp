#include "types.h"

typedef struct { int words[3]; } SsoString;
typedef struct { char unused; } Allocator; /* empty allocator object passed by value */
extern int strlen(const char* s); /* strlen */
extern void String_Reserve(SsoString* s, int capacity);
extern void* String_Replace(SsoString* s, int pos, int count, const char* first, const char* last, Allocator alloc);

/* String constructor from a C string. */
SsoString* String_CtorCStr(SsoString* self, const char* text)
{
    Allocator alloc;
    int len;
    self->words[0] = 0;
    self->words[1] = 0;
    self->words[2] = 0;
    len = strlen(text);
    String_Reserve(self, len);
    String_Replace(self, 0, 0, text, text + len, alloc);
    return self;
}
