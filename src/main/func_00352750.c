#pragma cplusplus on

#include "types.h"

/* Container assignment: assign [src.data, src.data + src.count) unless self-assignment. */
struct Tag352750 { char c; };
struct V352750 { int capacity; int count; char* data; };
extern "C" {
void func_00352910(V352750* self, char* first, char* last, Tag352750 tag);
V352750* func_00352750(V352750* self, V352750* src);
}
V352750* func_00352750(V352750* self, V352750* src)
{
    if (self != src) {
        Tag352750 tag;
        func_00352910(self, src->data, src->data + src->count, tag);
    }
    return self;
}