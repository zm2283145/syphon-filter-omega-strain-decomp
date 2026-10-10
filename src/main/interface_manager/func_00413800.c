#include "types.h"

typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { int unk0; int count; String* data; } StringVec;

extern void func_00138B70(String* s, int flags);

/* Removes the last string of the vector and destroys it. */
void StringVec_PopBack(StringVec* self)
{
    String* last = &self->data[--self->count];
    if (last)
        func_00138B70(last, 0);
}
