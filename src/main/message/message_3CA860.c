/*
 * main/message: 5 files, 003CA860-003CAA50
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003CA860 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Allocator release(ptr, pool, destroy, file, line): destroy the element's member at +4, then Mem_Free under the guard. */
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void* func_003CA940(void* self, short flags);
void func_003CA860(void* allocation, int pool, int destroy, char* file, int line);
}
void func_003CA860(void* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            func_003CA940((char*)allocation + 12, -1);
    }
    Mem_Free(pool, allocation, file, line);
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA860 */

/* merge_units: begin func_003CA940 */
#pragma push /* merge_units */
extern void func_003CA300(void* self, short del);
extern void operator_delete(void* p);
void* func_003CA940(void* self, short del)
{
    if (self) {
        void* m = (char*)self + 4;
        if (m)
            func_003CA300(m, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CA940 */

/* merge_units: begin func_003CA9A0 */
#pragma push /* merge_units */
extern char D_004BD178[];
extern void func_00136DA0(int* g);
extern void func_0012F530(int* g, int del);
#if 0 /* merge_units */
extern void Mem_Free(int heap, void* p, const char* file, int line);
#endif /* merge_units */
#define Mem_Free(a0, a1, a2, a3) (Mem_Free((a0), (a1), (char *)(a2), (a3))) /* merge_units */

void func_003CA9A0(void* self, void* p)
{
    if (p) {
        int g[1];
        func_00136DA0(g);
        Mem_Free(0, p, D_004BD178, 100);
        func_0012F530(g, -1);
    }
}
#undef Mem_Free /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003CA9A0 */

/* merge_units: begin func_003CAA00 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose04_types.h"

extern int func_003CA4D0(void* obj, int flags);

void* func_003CAA00(char* self) {
    return self + 4;
}

/* Destroys the object embedded 4 bytes into obj (flags -1) when obj is non-null. */
void func_003CAA10(void* self, char* obj) {
    if (obj != 0) {
        func_003CA4D0(obj + 4, -1);
    }
}

void* func_003CAA40(void* self) {
    return self;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CAA00 */

/* merge_units: begin func_003CAA50 */
#pragma push /* merge_units */
#pragma opt_common_subs off
typedef struct { char pad[8]; int* key; } Svc_c7;
typedef struct SvcNode_c7 { struct SvcNode_c7* prev; struct SvcNode_c7* next; Svc_c7* svc; } SvcNode_c7;
typedef struct { SvcNode_c7* p; } SvcIt_c7;
typedef struct { char pad[0x20]; int list; } SvcMgr_c7;
extern void func_0013B160(SvcIt_c7* out, void* list);
extern SvcIt_c7* func_003CAB40(SvcIt_c7* dst, SvcIt_c7* src);
extern void func_003CAB30(SvcIt_c7* out, void* list);
extern SvcIt_c7* func_003CAB20(SvcIt_c7* dst, SvcIt_c7* src);
Svc_c7* Service_Lookup(SvcMgr_c7* self, int* id) {
    SvcIt_c7 it;
    SvcIt_c7 beg;
    SvcIt_c7 end;
    SvcIt_c7 e0;
    SvcIt_c7 b0;
    SvcNode_c7* last;
    func_0013B160(&e0, &self->list);
    func_003CAB40(&end, &e0);
    last = end.p;
    func_003CAB30(&b0, &self->list);
    func_003CAB20(&beg, &b0);
    for (it = beg; it.p != last; it.p = it.p->next) {
        Svc_c7* s = it.p->svc; if (*s->key == *id) return s;
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003CAA50 */
