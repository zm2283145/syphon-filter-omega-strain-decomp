/*
 * main/texman: range (5 files, 00381000-003813A0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* library prototypes shared by the blocks below (C linkage) */
int Mem_Free();

/* merge_units: begin func_00381000 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int count; } E2List;
extern void func_0036E5D0(void*);
extern void func_0036E140(void*, void*, int, int);
extern int TexMan_FindOrLoad(E2List*, void*);
extern void FileMan_Release(void*, int);
int TexCache_LoadErrorTexture(E2List* s) {
    char buf[0xA0];
    int r;
    func_0036E5D0(buf);
    func_0036E140(buf, "GAMEDATA\\COMMON\\ERROR.TDX", 0, 0);
    r = TexMan_FindOrLoad(s, buf);
    if (r == -1) r = s->count - 1;
    FileMan_Release(buf, -1);
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381000 */

/* merge_units: begin func_00381080 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct ListNode_381080 ListNode_381080;
typedef struct { int size; ListNode_381080* sentinelPrev; ListNode_381080* first; } List_381080;
typedef struct { char pad[0x10]; unsigned short h10; } S44_381080;
typedef struct { char pad[0x44]; S44_381080* p44; char pad2[0x60 - 0x48]; char b60; char b61; } Obj_381080;
typedef struct {
    char pad[8]; Obj_381080** arr; int total; int count;
    char pad14[0x41C - 0x14]; List_381080 l41C; List_381080 l428; List_381080 l434;
} Mgr_381080;
extern "C" {
extern char D_004BC2B8[];
void func_003BBBC0(Obj_381080* o, int flags);
void func_00383420(ListNode_381080** result, List_381080* list, ListNode_381080** first, ListNode_381080** last);
}
static inline void Free_381080(Obj_381080* o)
{
    AllocGuard g;
    func_003BBBC0(o, -1);
    Mem_Free(0, o, D_004BC2B8, 0x3D1);
}
static inline void ListClear_381080(List_381080* self)
{
    ListNode_381080* result;
    ListNode_381080* first;
    ListNode_381080* last;
    last = (ListNode_381080*)&self->sentinelPrev;
    first = self->first;
    func_00383420(&result, self, &first, &last);
}
static inline void Reset_381080(Mgr_381080* m)
{
    int i;
    for (i = 0; i < m->count; i++) {
        if (m->arr[i]) {
            m->arr[i]->b60 = 0;
            if (m->arr[i]->p44->h10 > 0)
                m->arr[i]->b61 = 0;
        }
    }
}
extern "C" void func_00381080(Mgr_381080* m)
{
    int i;
    Reset_381080(m);
    for (i = 0; i < m->total; i++) {
        if (m->arr[i]) {
            Free_381080(m->arr[i]);
            m->arr[i] = 0;
        }
    }
    ListClear_381080(&m->l428);
    ListClear_381080(&m->l434);
    ListClear_381080(&m->l41C);
    m->count = 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381080(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381080 */

/* merge_units: begin func_00381260 */
#pragma push /* merge_units */
#pragma push
#pragma cplusplus on
typedef struct Node_3812D0 {
    int pad0;
    int pad4;
    int value;
} Node_3812D0;
typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    unsigned char pad0C[0x428 - 0xC];
    int count;
    int pad42C;
    Node_3812D0* head;
    int freeA[3];
} Obj_3812D0;
extern "C" void func_003812D0(Obj_3812D0* o); /* gsynth: defined below */
#pragma pop
typedef struct { char pad[0x10]; unsigned short h10; } G7S44;
typedef struct { char pad[0x44]; G7S44* p44; char pad2[0x60 - 0x48]; char b60; char b61; } G7Obj;
typedef struct { char pad[8]; G7Obj** arr; int pad2; int count; } G7Mgr;
#if 0 /* merge_units */
extern void func_003812D0(G7Mgr* m);
#endif /* merge_units */
#define func_003812D0(a0) (func_003812D0((void *)(a0))) /* merge_units */

void func_00381260(G7Mgr* m)
{
    int i;
    for (i = 0; i < m->count; i++) {
        if (m->arr[i]) {
            m->arr[i]->b60 = 0;
            if (m->arr[i]->p44->h10 > 0) {
                m->arr[i]->b61 = 0;
            }
        }
    }
    func_003812D0(m);
}
#undef func_003812D0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381260(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381260 */

/* merge_units: begin func_003812D0 */
#pragma push /* merge_units */
#pragma cplusplus on





extern "C" {
extern char D_004BC300[];
int func_00380360(void* t);
void func_00380280(void* t, int a, int b, char* file, int line);
void func_003801A0(Obj_3812D0* o, int v);
void func_00380170(void* list, int* value);
}

extern "C" void func_003812D0(Obj_3812D0* o)
{
    while (o->count) {
        int v = o->head->value;
        int idx = v;
        if (o->tex[v] && func_00380360(o->tex[idx]) <= 0) {
            func_00380280(o->tex[idx], 0, 1, D_004BC300, 0x39E);
            o->tex[idx] = 0;
            func_003801A0(o, idx);
            func_00380170(o->freeA, &idx);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003812D0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003812D0 */

/* merge_units: begin func_003813A0 */
#pragma push /* merge_units */
#pragma cplusplus on

typedef struct {
    unsigned char pad0[0x8];
    void** tex;
    unsigned char pad0C[0x428 - 0xC];
    int list428[3];
    int freeA[3];
} Obj_3813A0;

extern "C" {
void TexEntry_Release(void* t);
#if 0 /* merge_units */
void func_003801A0(Obj_3813A0* o, int v);
#endif /* merge_units */
#define func_003801A0(a0, a1) (func_003801A0((Obj_3812D0 *)(a0), (a1))) /* merge_units */

}

extern "C" void func_003813A0(Obj_3813A0* o, int idx, int keep)
{
    int i = idx;
    if (o->tex[idx]) {
        TexEntry_Release(o->tex[idx]);
        if (func_00380360(o->tex[i]) == 0) {
            func_00380170(o->list428, &i);
        }
    }
    if (keep == 0) {
        int j = idx;
        if (o->tex[idx] && func_00380360(o->tex[idx]) <= 0) {
            func_00380280(o->tex[j], 0, 1, D_004BC300, 0x39E);
            o->tex[j] = 0;
            func_003801A0(o, j);
            func_00380170(o->freeA, &j);
        }
    }
}
#undef func_003801A0 /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003813A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003813A0 */
