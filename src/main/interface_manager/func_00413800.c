#include "types.h"

typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { int unk0; int count; String* data; } StringVec;

extern void String_Dtor(String* s, int flags);

/* Removes the last string of the vector and destroys it. */
void StringVec_PopBack(StringVec* self)
{
    String* last = &self->data[--self->count];
    if (last)
        String_Dtor(last, 0);
}
