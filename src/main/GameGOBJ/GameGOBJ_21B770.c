/*
 * main/GameGOBJ: range (2 files, 0021B770-0021B790)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "gobj_types.h"
#include "types.h"

/* merge_units: begin func_0021B770 */
#pragma push /* merge_units */
/*
 * Matched functions from GameGOBJ.cc (byte-identical with the retail executable).
 */


Rel* func_0021B770(Rel* r) {
    r->a = 0;
    r->b = 0;
    r->c = 0;
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021B770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021B770 */

/* merge_units: begin func_0021B790 */
#pragma push /* merge_units */
typedef struct Gobj {
    char pad[0xC];
    int handle;
} Gobj;

typedef struct TriggerEventMsg {
    void* vtable;
    char pad[0x20];
    int event;      /* 0x24 */
    int param;      /* 0x28 */
    int other;      /* 0x2C */
    int source;     /* 0x30 */
} TriggerEventMsg;

extern int g_TriggerMsgKey;
extern int D_004DAF10;
extern void cMessage_ctor_cMessageNameR(TriggerEventMsg*, void*);

/* Constructor: cGOBJTriggerEventMsg(event, param, source, other). */
TriggerEventMsg* cGOBJTriggerEventMsg_ctor(TriggerEventMsg* m, int event, int param, Gobj* source, Gobj* other) {
    cMessage_ctor_cMessageNameR(m, &g_TriggerMsgKey);
    m->vtable = &D_004DAF10;
    m->event = event;
    m->param = param;
    m->source = source != 0 ? source->handle : 0;
    m->other = other != 0 ? other->handle : 0;
    return m;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0021B790(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0021B790 */
