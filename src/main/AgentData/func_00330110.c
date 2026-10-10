#include "types.h"

typedef struct { void* buffer; int unk4; int index; int unkC; char pad[4]; int unk14; } Obj330;

extern void* D_004FFD30;
extern char* WeaponDb_Get(void* p);
extern void* Loc_FindKeyThunk(char* p);

/* Constructor: allocates the buffer and initializes the fields; returns self. */
Obj330* func_00330110(Obj330* self, int a, int b)
{
    self->buffer = Loc_FindKeyThunk(WeaponDb_Get(D_004FFD30) + 0x80);
    self->unk14 = a;
    self->unk4 = b;
    self->index = -1;
    self->unkC = 0;
    return self;
}
