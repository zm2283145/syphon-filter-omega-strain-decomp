#include "types.h"

typedef struct { char* begin; char* end; char* cap; } String;
typedef struct { String name; int unkC; int unk10; } NamedEntry;
typedef struct { int unk0; int count; NamedEntry* data; } EntryVec;

extern void func_00138B70(String* s, int flags);

static inline void NamedEntry_dtor(NamedEntry* e)
{
    if (e)
        func_00138B70(&e->name, 0);
}

/* Removes the last entry of the vector and destroys it. */
void func_004211C0(EntryVec* self)
{
    NamedEntry* last = &self->data[--self->count];
    if (last)
        NamedEntry_dtor(last);
}
