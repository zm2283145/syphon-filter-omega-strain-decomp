#include "types.h"

typedef struct { void* vtable; char pad[0x5C]; int script; unsigned char flag; char pad2[3]; int owner; } SubScript;

extern char D_004DFE40[];
extern void cGOBJ_ctor(SubScript* self, int* a, int b, int* c);

/* SubScript constructor. */
SubScript* SubScript_ctor(SubScript* self, int script, int owner)
{
    int c = 0;
    int a = 0;
    cGOBJ_ctor(self, &a, 0, &c);
    self->vtable = D_004DFE40;
    self->script = script;
    self->owner = owner;
    self->flag = 0;
    return self;
}
