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
extern void func_0016DDB0(Obj* self, int a, int b);
extern void func_0016DC60(Obj* self);

/* Constructor: initialises the collection, ids and flag bits, then resets state. */
Obj* func_0016E0A0(Obj* self, int owner)
{
    unsigned char off = 0;
    ScalarCollection_Init(self->coll);
    self->owner = owner;
    self->unk44 = -2;
    self->unk40 = 0;
    self->unk4C = -2;
    self->unk48 = 0;
    self->unk1C = -1;
    func_0016DDB0(self, 0, 0);
    self->f4 = off;
    self->f5 = off;
    self->f0 = off;
    self->unk18 = -1;
    func_0016DC60(self);
    return self;
}
