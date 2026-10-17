#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004BCCF8[];
extern char D_004BCD50[];
extern void Mem_Free(int pool, void* p, char* file, int line);
}
struct SkEnt {
    char* name; int count; int a, b;
    void Destroy() {
        char* p = name;
        if (p) {
            AllocGuard g2;
            Mem_Free(0, p, D_004BCD50, 0x66);
        }
    }
};
typedef struct SkNode { struct SkNode* prev; struct SkNode* next; SkEnt* e; } SkNode;
typedef struct { SkNode* n; } SkIt;
typedef struct { int pad; SkNode header; } SkList;
extern "C" {
extern void func_003AA500(SkIt* out, SkList* l);
extern SkIt* func_003AA4F0(SkIt* dst, SkIt* src);
extern void func_003AA4E0(SkIt* out, SkList* l);
extern void ObjectList_EraseRange(SkIt* out, SkList* l, SkIt* first, SkIt* last);
void Skel_FreeAll(SkList* l);
}

static inline void SkBegin(SkIt* out, SkList* l) { SkIt b; func_003AA500(&b, l); func_003AA4F0(out, &b); }
static inline void SkEnd(SkIt* out, SkList* l) { SkIt t; func_003AA4E0(&t, l); func_003AA4F0(out, &t); }

static inline void SkBegin2(SkIt* out, SkList* l) { SkBegin(out, l); }
static inline void SkEnd2(SkIt* out, SkList* l) { SkEnd(out, l); }

void Skel_FreeAll(SkList* l)
{
    SkIt it;
    SkIt end;
    SkEnt* e;
    SkNode* n;

    SkBegin2(&it, l);
    for (n = it.n; SkEnd2(&end, l), n != end.n; n = n->next) {
        e = n->e;
        AllocGuard g;
        if (e) {
            e->Destroy();
        }
        Mem_Free(0, e, D_004BCCF8, 0x20);
    }
    SkIt r;
    SkIt first;
    SkIt last;
    last.n = &l->header;
    first.n = l->header.next;
    ObjectList_EraseRange(&r, l, &first, &last);
}



