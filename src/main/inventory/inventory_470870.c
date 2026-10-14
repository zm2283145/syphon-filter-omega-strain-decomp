/*
 * main/inventory: range (4 files, 00470870-00470B20)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00470870 */
#pragma push /* merge_units */
typedef struct { int item; int count; } InvPair_h5;
typedef struct {
    int unk0;
    volatile int size;  /* 0x04 */
    InvPair_h5* data;   /* 0x08 */
    int unkC;
    void* owner;        /* 0x10 */
} Inventory_h5;
typedef struct {
    void* vtable;
    char base[0x18];
    int kind;            /* 0x1C */
    unsigned char b20;   /* 0x20 */
    char pad21[3];
    short item;          /* 0x24 */
    unsigned char count; /* 0x26 */
    unsigned char added; /* 0x27 */
} InvMsg_h5;
extern unsigned char D_005721C8;
extern char D_00587FC0[];
extern char D_004E1AC0[];
extern char D_004DCF10[];
extern void Event_Construct(InvMsg_h5* msg, void* name);
extern void Event_Send(InvMsg_h5* msg, void* target, int flags);
extern void cMessage_dtor(InvMsg_h5* msg, int flags);
extern void ItemInv_AppendPair(Inventory_h5* inv, InvPair_h5* pos, int n, InvPair_h5* val);
#pragma opt_strength_reduction off
void ItemInv_Add(Inventory_h5* inv, int item, int n, int silent)
{
    int i;
    InvPair_h5 pair;
    if (item <= -1) {
        return;
    }
    for (i = 0; i < inv->size; i++) {
        if (item == inv->data[i].item) {
            inv->data[i].count += n;
            return;
        }
    }
    pair.item = item;
    pair.count = n;
    ItemInv_AppendPair(inv, &inv->data[inv->size], 1, &pair);
    if (D_005721C8 && !silent) {
        InvMsg_h5 msg;
        Event_Construct(&msg, D_00587FC0);
        msg.vtable = D_004E1AC0;
        msg.b20 = 4;
        msg.kind = 0x40;
        msg.item = item;
        msg.count = n;
        msg.added = 1;
        Event_Send(&msg, inv->owner, 0);
        msg.vtable = D_004DCF10;
        cMessage_dtor(&msg, 0);
    }
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00470870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00470870 */

/* merge_units: begin func_004709C0 */
#pragma push /* merge_units */
/* Global_PlayerRemoveItem */
typedef struct { int key; char pad[40]; } Pt2_ItemDef;
extern int D_00587FF4;
extern Pt2_ItemDef* D_00587FF8;
extern int Loc_FindKeyThunk(char*);
extern void ItemInv_Remove(void*, int, int, int);
static inline int Pt2_FindDef(int key) {
    int i;
    for (i = 0; i < D_00587FF4; i++) {
        if (key == D_00587FF8[i].key) return i;
    }
    return -1;
}

#pragma opt_strength_reduction off
void Global_PlayerRemoveItem(void* inv, char* name, int n) {
    ItemInv_Remove(inv, Pt2_FindDef(Loc_FindKeyThunk(name)), n, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004709C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004709C0 */

/* merge_units: begin func_00470A70 */
#pragma push /* merge_units */
/* Global_PlayerAddItem */

#if 0 /* merge_units */
extern void ItemInv_Add(void*, int, int, int);
#endif /* merge_units */
#define ItemInv_Add(a0, a1, a2, a3) (ItemInv_Add((void *)(a0), (a1), (a2), (a3))) /* merge_units */


#pragma opt_strength_reduction off
void Global_PlayerAddItem(void* inv, char* name, int n) {
    ItemInv_Add(inv, Pt2_FindDef(Loc_FindKeyThunk(name)), n, 0);
}
#undef ItemInv_Add /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00470A70(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00470A70 */

/* merge_units: begin func_00470B20 */
#pragma push /* merge_units */
extern char* D_005061D0;
static inline short R16_00470B20(void) { unsigned char lo = *D_005061D0++; unsigned char hi = *D_005061D0++; return lo + (hi << 8); }
static inline int R32_00470B20(void) { unsigned short lo = R16_00470B20(); return lo + ((unsigned short)R16_00470B20() << 16); }
static inline float RF_00470B20(void) { int i = R32_00470B20(); return *(float*)&i; }
static inline char R8_00470B20(void) { return *D_005061D0++; }
typedef struct { void* vtable; char pad[0x20]; short a; char b; char c; char pad28[8]; } M_00470B20;
typedef struct { char pad[0x3528]; void* mgr; } T_00470B20;
#if 0 /* merge_units */
extern void Event_Construct(M_00470B20* m, void* type);
#endif /* merge_units */
#define Event_Construct(a0, a1) (Event_Construct((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void cMessage_dtor(M_00470B20* m, int flags);
#endif /* merge_units */
#define cMessage_dtor(a0, a1) (cMessage_dtor((void *)(a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern void ItemInv_Add(void* mgr, int a, int b, int c);
#endif /* merge_units */
#define ItemInv_Add(a0, a1, a2, a3) (ItemInv_Add((void *)(a0), (a1), (a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern void ItemInv_Remove(void* mgr, int a, int b, int c);
#endif /* merge_units */
#define ItemInv_Remove(a0, a1, a2, a3) (ItemInv_Remove((a0), (a1), (a2), (a3))) /* merge_units */

static inline void Read_00470B20(M_00470B20* m) { m->a = R16_00470B20(); m->b = R8_00470B20(); m->c = R8_00470B20(); }
void func_00470B20(T_00470B20* t) {
    M_00470B20 m;
    Event_Construct(&m, D_00587FC0);
    m.vtable = D_004E1AC0;
    Read_00470B20(&m);
    if (t) {
        if (m.c) ItemInv_Add(t->mgr, m.a, m.b, 1);
        else ItemInv_Remove(t->mgr, m.a, m.b, 1);
    }
    m.vtable = D_004DCF10;
    cMessage_dtor(&m, 0);
}
#undef Event_Construct /* merge_units */
#undef cMessage_dtor /* merge_units */
#undef ItemInv_Add /* merge_units */
#undef ItemInv_Remove /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00470B20(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00470B20 */
