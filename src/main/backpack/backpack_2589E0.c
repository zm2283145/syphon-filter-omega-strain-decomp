/*
 * main/backpack: range (3 files, 002589E0-00258BB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_002589E0 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0; /* network write cursor */

static inline void write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

static inline void write32(int v)
{
    write16((unsigned short)v);
    write16(v >> 16);
}

static inline void writeFloat(float f)
{
    write32(*(int*)&f);
}

typedef struct { char pad[0x24]; int a; int b; void* crate; } cCrateInteractMsg;
extern void func_00282020(void* crate);

/* cCrateInteractMsg virtual 4: serializes the crate, then writes both values little-endian. */
void cCrateInteractMsg_v04(cCrateInteractMsg* self)
{
    func_00282020(self->crate);
    write32(self->a);
    write32(self->b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002589E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002589E0 */

/* merge_units: begin func_00258B50 */
#pragma push /* merge_units */
/* Stack message object: vtable followed by the base message data. */
typedef struct Msg {
    void* vtable;
    char data[0x2C];
} Msg;

extern char D_004F7EA0[];
extern char D_004DC480[];        /* derived message vtable */
extern char D_004DCF10[]; /* base message vtable */
extern void Event_Construct(Msg* msg, void* name);
extern void cCrateInteractMsg_Apply(Msg* msg, void* target);
extern void cMessage_dtor(Msg* msg, int flags);

/* Builds a temporary message, sends it to target, then destroys it. */
void cCrateInteractMsg_NetReceive(void* target) {
    Msg msg;
    Event_Construct(&msg, D_004F7EA0);
    msg.vtable = D_004DC480;
    cCrateInteractMsg_Apply(&msg, target);
    msg.vtable = D_004DCF10;
    cMessage_dtor(&msg, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258B50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258B50 */

/* merge_units: begin func_00258BB0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cInventoryMsg virtual slot.
 */


extern int D_004F7EE8;

int cInventoryMsg_v05(void) {
    return D_004F7EE8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258BB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258BB0 */
