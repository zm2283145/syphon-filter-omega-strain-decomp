#include "types.h"
typedef struct { char pad[0x1F0]; char a; char b; } Sub0021A070;
typedef struct { void* vtable; char pad[0x5C]; unsigned char flag; char pad61[3]; Sub0021A070* sub; } Obj0021A070;
extern void cGameGOBJ_ctor(Obj0021A070* self, void* a1, void* a2, int kind);
extern char D_004DB3A0[];
Obj0021A070* func_0021A070(Obj0021A070* self, void* a1, void* a2)
{
    cGameGOBJ_ctor(self, a1, a2, 6);
    self->vtable = D_004DB3A0;
    if (self->flag) {
        self->sub->a = 0;
        self->sub->b = 0;
    }
    return self;
}