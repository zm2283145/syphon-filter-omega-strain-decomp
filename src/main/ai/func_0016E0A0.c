#include "types.h"

typedef struct {
    char pad[0x18];
    int unk18;
    int unk1C;
    unsigned char lo : 4;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char hi : 2;
    unsigned char f0 : 1;
    unsigned char rest : 7;
    char pad22[0xE];
    char coll[0xC];
    int owner;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
} Obj;
extern void ScalarCollection_Init(void* coll);
extern void NpcPerception_SetTarget(Obj* self, int a, int b);
extern void NpcPerception_Clear(Obj* self);

/* Constructor: initialises the collection, ids and flag bits, then resets state. */
Obj* NpcPerception_Construct(Obj* self, int owner)
{
    unsigned char off = 0;
    ScalarCollection_Init(self->coll);
    self->owner = owner;
    self->unk44 = -2;
    self->unk40 = 0;
    self->unk4C = -2;
    self->unk48 = 0;
    self->unk1C = -1;
    NpcPerception_SetTarget(self, 0, 0);
    self->f4 = off;
    self->f5 = off;
    self->f0 = off;
    self->unk18 = -1;
    NpcPerception_Clear(self);
    return self;
}
