/*
 * main/GobjMan: 8 files, 0040CFF0-0040D580
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0040CFF0 */
#pragma push /* merge_units */
#include "types.h"
#pragma cplusplus on
#include "tree_insert_v8.h"

extern "C" { char D_004BECC0[] = "tree::insert length error\n"; }
extern "C" { char D_004BECE0[] = "allocator.hh"; }
DEFINE_TREE_INSERT_V8(func_0040CFF0, TIValueII, D_004BECC0, D_004BECE0, 0x5C, func_0013CD40)
#pragma pop /* merge_units */
/* merge_units: end func_0040CFF0 */

/* merge_units: begin func_0040D160 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "guarded_release.h"

/* Free an allocation under the allocator guard. */
DEFINE_GUARDED_RELEASE(func_0040D160)
#pragma pop /* merge_units */
/* merge_units: end func_0040D160 */

/* merge_units: begin func_0040D210 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
extern "C" { extern char D_004BECF0[]; void Mem_Free(int pool, void* p, char* file, int line); }
extern "C" void func_0040D210(void* tree, void* node)
{
    if (node) {
        AllocGuard guard;
        Mem_Free(0, node, D_004BECF0, 0x64);
    }
}
#pragma pop /* merge_units */
/* merge_units: end func_0040D210 */

/* merge_units: begin func_0040D2B0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


void* func_0040D2B0(char* self) {
    return self + 4;
}

void func_0040D2C0(void) {
}

void* func_0040D2D0(void* self) {
    return self;
}

Map* func_0040D2E0(Map* m, unsigned char* cmp) {
    m->count = 0;
    m->head = 0;
    m->cmp = *cmp;
    m->hp = &m->head;
    return m;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040D2B0 */

/* merge_units: begin func_0040D300 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } TD300;
extern void func_0040CD10(TD300* t, void* n);
extern void operator_delete(void* p);
/* Deleting destructor of a tree owner: erase the root, then delete. */
TD300* func_0040D300(TD300* t, short del)
{
    if (t) {
        if (t->m4)
            func_0040CD10(t, t->m4);
        if (del > 0)
            operator_delete(t);
    }
    return t;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040D300 */

/* merge_units: begin func_0040D360 */
#pragma push /* merge_units */
typedef struct { int m0; void* m4; } TD360;
typedef struct { TD360 tree; } OD360;
#if 0 /* merge_units */
extern void func_0040D300(TD360* t, short del);
#endif /* merge_units */
#define func_0040D300(a0, a1) ((void)func_0040D300((TD300 *)(a0), (a1))) /* merge_units */

/* Deleting destructor of a tree wrapper. */
OD360* func_0040D360(OD360* o, short del)
{
    if (o) {
        TD360* t = &o->tree;
        if (t)
            func_0040D300(t, -1);
        if (del > 0)
            operator_delete(o);
    }
    return o;
}
#undef func_0040D300 /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0040D360 */

/* merge_units: begin func_0040D3C0 */
#pragma push /* merge_units */
#pragma cplusplus on

struct Ctx_D3C0 {
    char pad0[0x5A0];
    unsigned char f5A0;
};

struct Pump_D3C0 {
    Ctx_D3C0* ctx;
    bool ok;
    char pad5[3];
    void (*cb)();
    bool err;
};

extern "C" int func_0040E5D0(Ctx_D3C0* ctx);

static inline bool Step(Pump_D3C0* s)
{
    s->ok = func_0040E5D0(s->ctx) != 0;
    if (!s->ok) s->err = 0;
    if (s->cb) s->cb();
    return !s->ok;
}

static inline void Wait(Pump_D3C0* s)
{
    while (!Step(s) || !s->ctx->f5A0) {
    }
}

extern "C" void MemCard_Refresh(Pump_D3C0* s)
{
    Wait(s);
    s->ctx->f5A0 = 0;
    Wait(s);
    s->ctx->f5A0 = 0;
    Wait(s);
    s->ctx->f5A0 = 0;
    Wait(s);
}
#pragma pop /* merge_units */
/* merge_units: end func_0040D3C0 */

/* merge_units: begin func_0040D580 */
#pragma push /* merge_units */
typedef struct { char pad[0x59F]; unsigned char flag; } CD580;
typedef struct { CD580* cfg; } OD580;
/* Number of 1 KB blocks needed for a payload, plus overhead. */
int MemCard_GetSpaceNeeded(OD580* o, int bytes) {
    int n = (bytes + 0x3FF) / 1024 + 1;
    if (!o->cfg->flag)
        n += 0x2E;
    else if (bytes == 0)
        n = 0;
    return n;
}
#pragma pop /* merge_units */
/* merge_units: end func_0040D580 */
