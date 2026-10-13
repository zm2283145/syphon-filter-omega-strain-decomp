#pragma cplusplus on
#include "types.h"

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

struct Owner_00254990 { char pad0[0xC]; int id; };

struct BP {
    char pad00[0x60];
    unsigned char b60;
    char pad61[3];
    Slot slots[3];
    char pad2E0[4];
    int x2E4;
    char pad2E8[0x2F1 - 0x2E8];
    unsigned char b2F1;
    char pad2F2[0x2FC - 0x2F2];
    void* fx;
    Owner_00254990* holder;
    int holderId;
    bool Free() { return !x2E4; }
    bool NoHolder() { return !Holder(); }
    Owner_00254990* Holder() { bool n = !holder; return (n || holder->id == holderId) ? holder : 0; }
};

extern "C" {
extern int D_004FFD30;
extern int D_004FFBD0;
int WeaponInv_SlotOfItem(int id);
void* WeaponDb_Get(int db, int item);
int func_001A3730(Owner_00254990* o);
void func_00170DB0(int, void*);
int Object_Unregister(void*);
int Object_DeleteLater(void*, float);
void func_00254770(BP* bp);
}

static inline bool HolderReady(BP* bp) {
    bool r = true;
    if (!bp->NoHolder() && !func_001A3730(bp->Holder())) r = false;
    return r;
}

extern "C" void func_00254990(BP* bp) {
    Slot* s;
    int i;
    bool ok;
    bool all;
    for (i = 0, s = bp->slots; i < 3; i++, s++) {
        Entry* e = s->e;
        int j;
        for (j = 0; j < s->count; j++, e++) {
            if ((unsigned char)WeaponInv_SlotOfItem(e->item) == 4 && (e->n == 0 || e->amount[e->n - 1] == 0)) {
                j--;
                *e-- = s->e[--s->count];
            }
        }
    }
    ok = false;
    if (bp->Free()) {
        if (HolderReady(bp)) ok = true;
    }
    all = ok;
    if (ok) {
        int i2;
        Entry* e;
        Slot* s2;
        for (s2 = bp->slots, i2 = 0; all && i2 < 3; i2++, s2++) {
            if (s2->flag && !bp->b2F1) {
                all = false;
            } else if (s2->count) {
                int j;
                e = s2->e;
                WeaponDb_Get(D_004FFD30, s2->e[0].item);
                for (j = 0; all && j < s2->count; j++, e++) {
                    if (e->n) all = false;
                }
            }
        }
    }
    if (all) {
        if (bp->b60 == 1) {
            if (bp->fx) {
                func_00170DB0(D_004FFBD0, bp->fx);
                Object_Unregister(bp->fx);
                Object_DeleteLater(bp->fx, 0.1f);
                bp->fx = 0;
            }
        } else {
            func_00254770(bp);
        }
    }
}

