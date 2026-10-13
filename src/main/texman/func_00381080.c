#pragma cplusplus on
#include "types.h"
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
void Mem_Free(int heap, void* p, char* file, int line);
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



