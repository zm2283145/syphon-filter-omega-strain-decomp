/*
 * main/backpack: range (5 files, 002583F0-002587D0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"
#include "backpack_types.h"

/* merge_units: begin func_002583F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cInventoryMsg script natives and script type registration.
 */


extern int D_004F7EF8;
extern int D_004F7F00;
extern int cGOBJ_SOBJ_toInt(int who);
extern int* cMessage_SOBJ_getClassId(void);
extern void cScriptBase_declareParent(int type, int baseType);

int Script_cInventoryMsg_Who(cItemMsg** msg) {
    return cGOBJ_SOBJ_toInt((*msg)->who);
}

/* Volatile locals mirror the original stack temporaries. */
int Script_cInventoryMsg_Count(cItemMsg** msg) {
    volatile int count = (*msg)->count;
    return count;
}

int Script_cInventoryMsg_Taken(cItemMsg** msg) {
    volatile int taken = (*msg)->taken;
    return taken;
}

void cInventoryMsg_SOBJ_init(void) {
    int* base = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7F00, *base);
}

int cInventoryMsg_v03(void) {
    return D_004F7EF8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002583F0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002583F0 */

/* merge_units: begin func_00258480 */
#pragma push /* merge_units */
extern unsigned char* D_005061D0; /* network read cursor */

static inline short read16(void)
{
    unsigned char lo = *D_005061D0++;
    unsigned char hi = *D_005061D0++;
    return lo + (hi << 8);
}

static inline int read32(void)
{
    unsigned short lo = read16();
    return lo + ((unsigned short)read16() << 16);
}

typedef struct { char pad[0x20]; unsigned char received; char pad21[3]; int a; int b; char item[1]; } cInventoryMsg;
extern void cNetMsg_GetGOBJ(void* item);
extern void QueueMessage_cMessageR_cSystemP_int(cInventoryMsg* msg, void* target, int flags);

/* cInventoryMsg receive: reads the item and two 32-bit values, then dispatches to target. */
void cInventoryMsg_UnpackAndProcess(cInventoryMsg* self, void* target)
{
    cNetMsg_GetGOBJ(self->item);
    self->a = read32();
    self->b = read32();
    self->received = 1;
    QueueMessage_cMessageR_cSystemP_int(self, target, 0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258480(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258480 */

/* merge_units: begin func_00258600 */
#pragma push /* merge_units */
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

typedef struct { char pad[0x24]; int a; int b; void* item; } cInventoryMsg_00258600;
extern void cNetMsg_PutGOBJ(void* item);

/* cInventoryMsg virtual 4: serializes the item, then writes two 32-bit values. */
void cInventoryMsg_Pack(cInventoryMsg_00258600* self)
{
    cNetMsg_PutGOBJ(self->item);
    write32(self->a);
    write32(self->b);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258600(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258600 */

/* merge_units: begin func_00258770 */
#pragma push /* merge_units */
typedef struct { void* vtable; char data[0x2C]; } Visitor; /* 0x30-byte stack object */
extern char D_004F7EE0[];
extern char D_004DC460[]; /* visitor vtable */
extern char D_004DCF10[]; /* base vtable */
extern void cMessage_ctor_cMessageNameR(Visitor* v, const char* name);
#if 0 /* merge_units */
extern void cInventoryMsg_UnpackAndProcess(Visitor* v, void* target);
#endif /* merge_units */
#define cInventoryMsg_UnpackAndProcess(a0, a1) (cInventoryMsg_UnpackAndProcess((void *)(a0), (a1))) /* merge_units */

extern void cMessage_dtor(Visitor* v, int flags);

/* Runs a temporary visitor object over target. */
void cInventoryMsg_NetReceive(void* target)
{
    Visitor v;
    cMessage_ctor_cMessageNameR(&v, D_004F7EE0);
    v.vtable = D_004DC460;
    cInventoryMsg_UnpackAndProcess(&v, target);
    v.vtable = D_004DCF10;
    cMessage_dtor(&v, 0);
}
#undef cInventoryMsg_UnpackAndProcess /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00258770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00258770 */

/* merge_units: begin func_002587D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * cCrateInteractMsg script natives and script type registration.
 */


extern int D_004F7EB8;
extern int D_004F7EC0;

int Script_cCrateInteractMsg_Who(cItemMsg** msg) {
    return cGOBJ_SOBJ_toInt((*msg)->who);
}

/* Volatile locals mirror the original stack temporaries. */
int Script_cCrateInteractMsg_Taken(cItemMsg** msg) {
    volatile int taken = (*msg)->taken;
    return taken;
}

int Script_cCrateInteractMsg_Given(cItemMsg** msg) {
    volatile int given = (*msg)->count;
    return given;
}

void cCrateInteractMsg_SOBJ_init(void) {
    int* base = cMessage_SOBJ_getClassId();
    cScriptBase_declareParent(D_004F7EC0, *base);
}

int cCrateInteractMsg_v03(void) {
    return D_004F7EB8;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_002587D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_002587D0 */
