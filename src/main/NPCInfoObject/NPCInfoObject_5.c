/*
 * main/NPCInfoObject: 8 files, 004373A0-004374F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004373A0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { extern char D_004BFD10[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_004373A0(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_004BFD10, 0x64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_004373A0 */

/* merge_units: begin func_00437440 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Translation unit: NPCInfoObject.cc.
 */


void* func_00437440(char* self) {
    return self + 4;
}

void func_00437450(void) {
}

void* func_00437460(void* self) {
    return self;
}

Map* func_00437470(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_00437440 */

/* merge_units: begin func_00437490 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_00437490;
extern void func_00436EA0(R1Tree_00437490* t, void* n);
extern void operator_delete(void* p);
R1Tree_00437490* func_00437490(R1Tree_00437490* t, short del)
{
    if (t) {
        if (t->m4)
            func_00436EA0(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_00437490 */

/* merge_units: begin func_004374F0 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } R1Tree_004374F0;
typedef struct { R1Tree_004374F0 tree; } R1Own_004374F0;
#if 0 /* merge_units */
extern void func_00437490(R1Tree_004374F0* t, short del);
#endif /* merge_units */
#define func_00437490(a0, a1) ((void)func_00437490((R1Tree_00437490 *)(a0), (a1))) /* merge_units */

R1Own_004374F0* func_004374F0(R1Own_004374F0* o, short del)
{
    if (o) {
        R1Tree_004374F0* t = &o->tree;
        if (t)
            func_00437490(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#undef func_00437490 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_004374F0 */

/* merge_units: begin func_00437550 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "base_dtor_chain.h"

/* Deleting destructor that runs the base destructor. */
DEFINE_BASE_DTOR_CHAIN(func_00437550, func_00135C90)
#pragma pop /* merge_units */
/* merge_units: end func_00437550 */

/* merge_units: begin func_004375B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Address lies between NPCInfoObject.cc (ends 0x00437490) and GenInfoObject.cc.
 */


/* Clears four bytes. */
char* func_004375B0(char* bytes) {
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
    bytes[3] = 0;
    return bytes;
}
#pragma pop /* merge_units */
/* merge_units: end func_004375B0 */

/* merge_units: begin func_004375D0 */
#pragma push /* merge_units */
extern volatile unsigned char D_005723C8;
extern volatile int D_00582CF0;

/* Reset the shared NPC information state. */
void func_004375D0(void)
{
    if (D_005723C8 == 0)
        D_005723C8 = 1;
    D_00582CF0 = 0;
    D_005723C8 = 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_004375D0 */

/* merge_units: begin func_00437600 */
#pragma push /* merge_units */
typedef struct { int unk0; int value; } Entry4;
extern void* D_00583870;
extern void func_002EB650(Entry4** out, void* key);

/* Looks up the global key and returns the entry's value, or -1 if not found. */
int func_00437600(void)
{
    Entry4* entry;
    func_002EB650(&entry, D_00583870);
    if (entry)
        return entry->value;
    return -1;
}
#pragma pop /* merge_units */
/* merge_units: end func_00437600 */
