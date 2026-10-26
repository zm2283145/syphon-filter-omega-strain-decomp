/*
 * main/NetObjectMgr: range (2 files, 0042D300-0042D310)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0042D300 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int NetObjectMgr_RemoveTransferTimer(int);

int func_0042D300(int a0) {
    return NetObjectMgr_RemoveTransferTimer(a0);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0042D300(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0042D300 */

/* merge_units: begin func_0042D310 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on

struct Obj {
    virtual void v00();
    virtual int GetValue(); /* +0xC */
};

typedef struct Pair { int key; int value; } Pair;

typedef struct InsertResult { void* it; unsigned char inserted; } InsertResult;

extern char D_005826E0[];
extern "C" void func_0042F400(InsertResult* out, void* map, Pair* p);

/* Inserts the pair (self key, value from obj virtual +0xC) into the D_005826E0 map. */
extern "C" void cNetObjectMgr_AddCopyMsg(int* self, Obj* obj)
{
    Pair p;
    InsertResult result;
    int value = obj->GetValue();
    p.key = *self;
    p.value = value;
    func_0042F400(&result, D_005826E0, &p);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0042D310(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0042D310 */
