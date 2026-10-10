#include "types.h"

typedef struct String {
    int a, b, c;
} String;

/* Empty tag object passed by value (an allocator in the original C++). */
typedef struct Tag {
    signed char unused;
} Tag;

extern int strlen(const char*);
extern void String_Reserve(String*, int);
extern void String_Replace(String*, int, int, const char*, const char*, Tag);

/* Constructs a string from a C string. */
String* func_00328890(String* self, const char* text) {
    Tag tag;
    int len;
    self->a = 0;
    self->b = 0;
    self->c = 0;
    len = strlen(text);
    String_Reserve(self, len);
    String_Replace(self, 0, 0, text, text + len, tag);
    return self;
}
