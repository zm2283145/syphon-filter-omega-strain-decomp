/*
 * main/texman: 2 files, 00380DB0-00380FB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00380DB0 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

typedef struct Node_380DB0 { struct Node_380DB0* prev; struct Node_380DB0* next; int value; } Node_380DB0;
typedef struct { Node_380DB0* p; } It_380DB0;
typedef struct { int count; Node_380DB0* prev; Node_380DB0* next; } List_380DB0;
typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    int pad0C;
    int next;
    unsigned char pad14[0x428 - 0x14];
    List_380DB0 freeB;
    List_380DB0 freeA;
} Obj_380DB0;

extern "C" {
extern char D_004BC2B8[], D_004BC300[];
void std_list_deleter_int_erase_listdeleter(It_380DB0* result, void* list, It_380DB0* pos);
int cTexture_GetRefCount(void* t);
void opDelete_cTextureP_int_bool_charP_etc(void* t, int a, int b, char* file, int line);
void cTexMan_EraseDeletedTID(Obj_380DB0* o, int v);
void* cMemMan_Allocate(int pool, unsigned int size, char* file, int line);
void* cTexture_ctor(void* t);
void cTexture_Init_charP_int_int_int_etc(void* t, int a, int b, int c, int d, int e);
}

static inline void Erase(It_380DB0* out, List_380DB0* l, It_380DB0* b) { It_380DB0 result; It_380DB0 value; value = *b; std_list_deleter_int_erase_listdeleter(&result, l, &value); *out = result; }

extern "C" int cTexMan_AddTexture(Obj_380DB0* o, int a, int b, int c, int d)
{
    int idx;
    void* t;
    if (o->freeA.count) {
        It_380DB0 r;
        It_380DB0 pos;
        Node_380DB0* n = o->freeA.next;
        idx = n->value;
        pos.p = n;
        Erase(&r, &o->freeA, &pos);
    } else if (o->freeB.count) {
        It_380DB0 r;
        It_380DB0 pos;
        Node_380DB0* n = o->freeB.next;
        idx = n->value;
        pos.p = n;
        Erase(&r, &o->freeB, &pos);
    } else {
        idx = o->next++;
    }
    if (o->tex[idx] && cTexture_GetRefCount(o->tex[idx]) <= 0) {
        opDelete_cTextureP_int_bool_charP_etc(o->tex[idx], 0, 1, D_004BC300, 0x39E);
        o->tex[idx] = 0;
        cTexMan_EraseDeletedTID(o, idx);
    }
    {
        AllocGuard guard;
        t = cMemMan_Allocate(0, 0x70, D_004BC2B8, 0x41B);
    }
    if (t) {
        t = cTexture_ctor(t);
    }
    o->tex[idx] = t;
    cTexture_Init_charP_int_int_int_etc(o->tex[idx], a, b, c, d, 0);
    return idx;
}
#pragma pop /* merge_units */
/* merge_units: end func_00380DB0 */

/* merge_units: begin func_00380FB0 */
#pragma push /* merge_units */
typedef struct { char pad[0x64]; int refs; } RefObj;
typedef struct { char pad[8]; RefObj** items; char pad2[4]; int count; } RefTable;

/* Increments the reference count of item index; returns 1 if the item exists. */
unsigned char cTexMan_AddTextureReference(RefTable* self, int index)
{
    unsigned char ok = 0;
    RefObj* obj;
    if (index >= 0 && index < self->count && (obj = self->items[index]) != 0) {
        obj->refs++;
        ok = 1;
    }
    return ok;
}
#pragma pop /* merge_units */
/* merge_units: end func_00380FB0 */
