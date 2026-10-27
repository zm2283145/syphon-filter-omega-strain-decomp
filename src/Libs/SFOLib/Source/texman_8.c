/*
 * Libs/SFOLib/Source/texman: 7 files, 00380DB0-00381000
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
static inline void merge_flush_func_00380DB0(void) {} /* merge_units */
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
static inline void merge_flush_func_00380FB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00380FB0 */

/* merge_units: begin func_00381000 */
#pragma push /* merge_units */
/* library prototypes shared by the blocks below (C linkage) */
int cMemMan_Deallocate();

typedef struct { char pad[0x10]; int count; } E2List;
extern void cFileMan_ctor_void(void*);
extern void cFileMan_EncodeFilename_charP_cFileIOP_bool(void*, void*, int, int);
extern int cTexMan_AddTextureFromFile_cFileManR(E2List*, void*);
extern void cFileMan_dtor(void*, int);
int cTexMan_UseMrYuckTexture(E2List* s) {
    char buf[0xA0];
    int r;
    cFileMan_ctor_void(buf);
    cFileMan_EncodeFilename_charP_cFileIOP_bool(buf, "GAMEDATA\\COMMON\\ERROR.TDX", 0, 0);
    r = cTexMan_AddTextureFromFile_cFileManR(s, buf);
    if (r == -1) r = s->count - 1;
    cFileMan_dtor(buf, -1);
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381000(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00381000 */

/* merge_units: begin func_00381080 */
#pragma push /* merge_units */
#pragma cplusplus on
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
void cTexture_dtor(Obj_381080* o, int flags);
void std_list_deleter_int_erase_listdeleter_listdeleter(ListNode_381080** result, List_381080* list, ListNode_381080** first, ListNode_381080** last);
}
static inline void Free_381080(Obj_381080* o)
{
    AllocGuard g;
    cTexture_dtor(o, -1);
    cMemMan_Deallocate(0, o, D_004BC2B8, 0x3D1);
}
static inline void ListClear_381080(List_381080* self)
{
    ListNode_381080* result;
    ListNode_381080* first;
    ListNode_381080* last;
    last = (ListNode_381080*)&self->sentinelPrev;
    first = self->first;
    std_list_deleter_int_erase_listdeleter_listdeleter(&result, self, &first, &last);
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
extern "C" void cTexMan_FlushTextures(Mgr_381080* m)
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
extern "C" void cTexMan_FlushDeletedTextures(Obj_3812D0* o); /* gsynth: defined below */
#pragma pop
typedef struct { char pad[0x10]; unsigned short h10; } G7S44;
typedef struct { char pad[0x44]; G7S44* p44; char pad2[0x60 - 0x48]; char b60; char b61; } G7Obj;
typedef struct { char pad[8]; G7Obj** arr; int pad2; int count; } G7Mgr;
#if 0 /* merge_units */
extern void cTexMan_FlushDeletedTextures(G7Mgr* m);
#endif /* merge_units */
#define cTexMan_FlushDeletedTextures(a0) ((void)cTexMan_FlushDeletedTextures((Obj_3812D0 *)(a0))) /* merge_units */


void cTexMan_Flush(G7Mgr* m)
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
    cTexMan_FlushDeletedTextures(m);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00381260(void) {}
#undef cTexMan_FlushDeletedTextures /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00381260 */

/* merge_units: begin func_003812D0 */
#pragma push /* merge_units */
#pragma cplusplus on





extern "C" {
extern char D_004BC300[];
#if 0 /* merge_units */
void cTexMan_EraseDeletedTID(Obj_3812D0* o, int v);
#endif /* merge_units */
#define cTexMan_EraseDeletedTID(a0, a1) (cTexMan_EraseDeletedTID((Obj_380DB0 *)(a0), (a1))) /* merge_units */

void cLList_int_PushBackActual(void* list, int* value);
}

extern "C" void cTexMan_FlushDeletedTextures(Obj_3812D0* o)
{
    while (o->count) {
        int v = o->head->value;
        int idx = v;
        if (o->tex[v] && cTexture_GetRefCount(o->tex[idx]) <= 0) {
            opDelete_cTextureP_int_bool_charP_etc(o->tex[idx], 0, 1, D_004BC300, 0x39E);
            o->tex[idx] = 0;
            cTexMan_EraseDeletedTID(o, idx);
            cLList_int_PushBackActual(o->freeA, &idx);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003812D0(void) {}
#undef cTexMan_EraseDeletedTID /* merge_units */
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
void cTexture_DecRefCount(void* t);
#if 0 /* merge_units */
void cTexMan_EraseDeletedTID(Obj_3813A0* o, int v);
#endif /* merge_units */
#define cTexMan_EraseDeletedTID(a0, a1) (cTexMan_EraseDeletedTID((Obj_380DB0 *)(a0), (a1))) /* merge_units */


}

extern "C" void cTexMan_RemoveTexture(Obj_3813A0* o, int idx, int keep)
{
    int i = idx;
    if (o->tex[idx]) {
        cTexture_DecRefCount(o->tex[idx]);
        if (cTexture_GetRefCount(o->tex[i]) == 0) {
            cLList_int_PushBackActual(o->list428, &i);
        }
    }
    if (keep == 0) {
        int j = idx;
        if (o->tex[idx] && cTexture_GetRefCount(o->tex[idx]) <= 0) {
            opDelete_cTextureP_int_bool_charP_etc(o->tex[j], 0, 1, D_004BC300, 0x39E);
            o->tex[j] = 0;
            cTexMan_EraseDeletedTID(o, j);
            cLList_int_PushBackActual(o->freeA, &j);
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003813A0(void) {}
#undef cTexMan_EraseDeletedTID /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003813A0 */
