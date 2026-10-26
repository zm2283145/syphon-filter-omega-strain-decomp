/*
 * main/inventory: range (4 files, 004704F0-004706C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_004704F0 */
#pragma push /* merge_units */
/* ItemInv_Any */
typedef struct { int id; int count; } Pt2_Item;
typedef struct { int pad0; int n; Pt2_Item* items; } Pt2_ItemInv;

#pragma opt_strength_reduction off
int ItemInv_Any(Pt2_ItemInv* inv) {
    int i;
    for (i = 0; i < *(volatile int*)&inv->n; i++) {
        if (inv->items[i].count) return 1;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004704F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004704F0 */

/* merge_units: begin func_00470560 */
#pragma push /* merge_units */
/* ItemInv_Count */


static inline Pt2_Item* Find(Pt2_ItemInv* inv, int id) {
    int i;
    for (i = 0; i < *(volatile int*)&inv->n; i++) {
        if (id == inv->items[i].id) return &inv->items[i];
    }
    return 0;
}
#pragma opt_strength_reduction off
int ItemInv_Count(Pt2_ItemInv* inv, int id) {
    Pt2_Item* e = Find(inv, id);
    return e ? e->count : 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00470560(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00470560 */

/* merge_units: begin func_004705D0 */
#pragma push /* merge_units */
/* Global_PlayerGetItemCount */
typedef struct { int key; char pad[40]; } Pt2_ItemDef;
extern int D_00587FF4;
extern Pt2_ItemDef* D_00587FF8;
extern int Loc_FindKeyThunk(char*);
static inline int Pt2_FindDef(int key) {
    int i;
    for (i = 0; i < D_00587FF4; i++) {
        if (key == D_00587FF8[i].key) return i;
    }
    return -1;
}

#pragma opt_strength_reduction off
int Global_PlayerGetItemCount(Pt2_ItemInv* inv, char* name) {
    int idx = Pt2_FindDef(Loc_FindKeyThunk(name));
    if (idx > -1) {
        int i;
        for (i = 0; i < *(volatile int*)&inv->n; i++) {
            if (idx == inv->items[i].id) return inv->items[i].count;
        }
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004705D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004705D0 */

/* merge_units: begin func_004706C0 */
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
extern unsigned char g_IsMultiplayer;
extern char D_00587FC0[];
extern void Message_GetScriptTypeKey();
extern void cNetInventoryMsg_dtor();
extern void cNetInventoryMsg_v01();
extern void cNetInventoryMsg_v04();
extern void cNetInventoryMsg_v05();
extern void cNetMsg_Pack();
void * const D_004E1AC0[8] = { (void*)0x0, (void*)0x0, (void*)cNetInventoryMsg_dtor, (void*)cNetInventoryMsg_v01, (void*)cNetMsg_Pack, (void*)Message_GetScriptTypeKey, (void*)cNetInventoryMsg_v04, (void*)cNetInventoryMsg_v05 };
extern char D_004DCF10[];
extern void Event_Construct(InvMsg_h5* msg, void* name);
extern void Event_Send(InvMsg_h5* msg, void* target, int flags);
extern void cMessage_dtor(InvMsg_h5* msg, int flags);
extern void ItemInv_AppendPair(Inventory_h5* inv, InvPair_h5* pos, int n, InvPair_h5* val);
#pragma opt_strength_reduction off
int ItemInv_Remove(Inventory_h5* inv, int item, int n, int silent)
{
    int i;
    if (item > -1)
    for (i = 0; i < inv->size; i++) {
        if (item == inv->data[i].item) {
            int removed = n;
            if (n < inv->data[i].count) {
                inv->data[i].count -= n;
            } else {
                removed = inv->data[i].count;
                inv->data[i].count = 0;
            }
            if (g_IsMultiplayer && !silent) {
                InvMsg_h5 msg;
                Event_Construct(&msg, D_00587FC0);
                msg.vtable = ((char*)D_004E1AC0);
                msg.b20 = 4;
                msg.kind = 0x40;
                msg.item = item;
                msg.count = n;
                msg.added = 0;
                Event_Send(&msg, inv->owner, 0);
                msg.vtable = D_004DCF10;
                cMessage_dtor(&msg, 0);
            }
            return removed;
        }
    }
    return 0;
}
#pragma opt_strength_reduction reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_004706C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_004706C0 */
