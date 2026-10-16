#include "types.h"

typedef struct { char tag; } Alloc;
typedef struct { char* begin; char* end; char* cap; } String;

extern int strlen(const char* s); /* strlen */
extern void String_Reserve(String* self, int n);
extern void String_Replace(String* self, char* at, int unused, const char* first, const char* last, Alloc alloc);

/* Constructs a string from a C string; returns self. */
String* func_00465F20(String* self, const char* s)
{
    int len;
    Alloc alloc;
    self->begin = 0;
    self->end = 0;
    self->cap = 0;
    len = strlen(s);
    String_Reserve(self, len);
    String_Replace(self, 0, 0, s, s + len, alloc);
    return self;
}
