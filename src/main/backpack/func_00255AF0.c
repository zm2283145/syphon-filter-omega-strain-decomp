#include "types.h"
#pragma cplusplus on

struct Link {
    char pad00[0x94];
    int owner;
};

struct Entry {
    int amount[4];
    int extra[4];
    int item;
    int n;
};

struct Slot {
    unsigned char kind;
    Entry e[5];
    int count;
    unsigned char flag;
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
    Slot slots[3];
    char pad2E0[0x2FC - 0x2E0];
    Link* link;
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

extern "C" void func_00255AF0(BP* bp, int item, int amount, int extra, unsigned char flag) {
    int kind = WeaponInv_SlotOfItem(item);
    unsigned char k = kind;
    int found = -1;
    int i;
    if (k == 4 && amount == 0)
        return;
    for (i = 0; i < 3; i++) {
        if (bp->slots[i].count || bp->slots[i].flag) {
            if (bp->slots[i].kind == k) {
                found = i;
                break;
            }
        } else if (found < 0) {
            found = i;
        }
    }
    if (found >= 0) {
        Slot* s = &bp->slots[found];
        bool done = false;
        Entry* e = s->e;
        int j = 0;
        for (; !done && j < s->count; j++, e++) {
            if (e->item == item) {
                if (k == 4) {
                    e->amount[0] += amount;
                } else {
                    e->amount[e->n] = amount;
                    e->extra[e->n] = extra;
                    e->n++;
                }
                done = true;
            }
        }
        if (!done) {
            e->item = item;
            e->extra[0] = extra;
            e->amount[0] = amount;
            e->n = 1;
            s->kind = kind;
            s->count++;
            if (flag)
                s->flag = flag;
        }
    }
    if (bp->link == 0) {
        bp->Method5C(1);
        Object_Register(bp);
        CreateLink(bp);
    }
}


