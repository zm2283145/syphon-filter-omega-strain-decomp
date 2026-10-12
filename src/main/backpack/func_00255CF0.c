#include "types.h"
#pragma cplusplus on

struct Link {
    char pad00[0x94];
    int owner;
};

struct BP {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14();
    virtual void Method5C(int a); /* +0x5C */
    char pad04[0x0C - 0x04];
    int unk0C;
    char pad10[0x64 - 0x10];
    signed char slot;
    char pad65[0x134 - 0x65];
    unsigned char unk134;
    char pad135[0x2F1 - 0x135];
    unsigned char unk2F1;
    char pad2F2[0x2FC - 0x2F2];
    Link* link;
    char pad300[0x30C - 0x300];
    int unk30C;
};

extern "C" {
extern int D_004FFBD0;
int WeaponInv_SlotOfItem(int id);
void Object_Register(BP* self);
Link* Hotbox_CreateRuntime(int manager, BP* bp, int a2, int a3);
}

static inline void CreateLink(BP* bp) {
    if (bp->link == 0) {
        bp->link = Hotbox_CreateRuntime(D_004FFBD0, bp, 0, 1);
        bp->link->owner = bp->unk0C;
    }
}

extern "C" void func_00255CF0(BP* bp, int item) {
    signed char s = WeaponInv_SlotOfItem(item);
    bp->unk134 = 1;
    bp->slot = s;
    if (bp->link == 0) {
        bp->Method5C(1);
        Object_Register(bp);
        CreateLink(bp);
    }
    bp->unk2F1 = 1;
    bp->unk30C = 0;
}

