#pragma cplusplus on
#include "types.h"

struct Owner_7A40 { char pad0[0xC]; int id; };

struct BP_7A40 {
    char pad00[0x60];
    unsigned char b60;
    char pad61[0x2F2 - 0x61];
    unsigned char b2F2;
    char pad2F3[0x2FC - 0x2F3];
    void* fx;
    Owner_7A40* holder;
    int holderId;
    int owner;
    int level;
    float dist;
    float timer;
    bool NoHolder() { return !Holder(); }
    Owner_7A40* Holder() { bool n = !holder; return (n || holder->id == holderId) ? holder : 0; }
};

struct List_7A40 { int pad0; int count; BP_7A40** items; };

extern "C" {
extern List_7A40* D_004F7F30;
extern int D_0048AF10;
extern int D_00494178;
extern int D_005721A8;
extern unsigned char D_005721C8;
extern int D_004FFBD0;
int func_001A3730(Owner_7A40* o);
int NetGame_InitLocalSlot(int*, int);
void func_00170DB0(int, void*);
int Object_Unregister(void*);
int Object_DeleteLater(void*, float);
}

static inline bool HolderReady(BP_7A40* bp) {
    bool r = true;
    if (!bp->NoHolder() && !func_001A3730(bp->Holder())) r = false;
    return r;
}

#pragma opt_strength_reduction off
extern "C" void func_00257A40(void) {
    List_7A40* list = D_004F7F30;
    int n;
    int cnt;
    int i;
    if (!list) return;
    n = list->count;
    cnt = 0;
    for (i = 0; i < n; i++) {
        BP_7A40* bp = list->items[i];
        if (bp->b60 == 0 && bp->level > 1) {
            if (HolderReady(bp)) cnt++;
        }
    }
    if (cnt > D_0048AF10) {
        int best = 0;
        int me;
        {
            int a = D_005721A8;
            if (D_005721C8) {
                if (D_00494178 == -1) NetGame_InitLocalSlot(&D_00494178, a);
                me = D_00494178;
            } else me = 0;
        }
        int j;
        for (j = 0; j < n; j++) {
            BP_7A40* bp = list->items[j];
            if (!D_005721C8 || bp->owner == me) {
                if (HolderReady(bp)) {
                    if (bp->level > best && !bp->b2F2 && bp->timer < 0.0f) best = bp->level;
                }
            }
        }
        if (best > 1) {
            BP_7A40* sel = 0;
            float bestd = 1e7f;
            int k;
            for (k = 0; k < n; k++) {
                BP_7A40* bp = list->items[k];
                if (!D_005721C8 || bp->owner == me) {
                    if (HolderReady(bp) && bp->level == best && !bp->b2F2 && bp->timer < 0.0f) {
                        if (bp->dist < bestd) {
                            bestd = bp->dist;
                            sel = bp;
                        }
                    }
                }
            }
            sel->b2F2 = 1;
            sel->timer = 0.0f;
            if (sel->fx) {
                func_00170DB0(D_004FFBD0, sel->fx);
                Object_Unregister(sel->fx);
                Object_DeleteLater(sel->fx, 0.1f);
                sel->fx = 0;
            }
        }
    }
}
