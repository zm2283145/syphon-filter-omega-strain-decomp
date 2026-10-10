#include "types.h"

typedef struct Rec14 {
    char b[0x14];
} Rec14;

typedef struct Vec14 {
    int unk0;
    int count;
    Rec14* data;
} Vec14;

/* Empty tag object passed by value (an allocator in the original C++). */
typedef struct Tag {
    signed char unused;
} Tag;

extern void Array_CopyRange20(Vec14*, Rec14*, Rec14*, Tag);

/* Copy-constructs a vector of 20-byte records. */
Vec14* func_0018A810(Vec14* self, Vec14* other) {
    Tag tag;
    self->unk0 = 0;
    self->count = 0;
    self->data = 0;
    Array_CopyRange20(self, other->data, other->data + other->count, tag);
    return self;
}
