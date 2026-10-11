#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct PopReader_1C10C0 { int unk0; int size; unsigned int base; char* cur; };
struct Node_1C10C0 { char pad[0x64]; unsigned int flags; };
struct Vec_1C10C0 { int cap; int count; Node_1C10C0** data; };
extern "C" {
extern char D_0049EE88[];
extern char D_0049EF70[];
extern Vec_1C10C0* D_004FFBE0;
extern char D_004FFB50[];
void* Mem_Alloc(int pool, int size, char* file, int line);
int Pop_FindTag(PopReader_1C10C0* r, int tag);
Node_1C10C0* Node_Construct(void* p, PopReader_1C10C0* r, int i);
void func_00165E60(void* a, char* name, int x);
void* func_001698C0(void);
void PtrVector_Resize(Vec_1C10C0* v, int n, void** fill);
void func_0040C940(Node_1C10C0* n);
void World_RegisterNode(void* w, Node_1C10C0* n);
}
#pragma opt_strength_reduction off
extern "C" void Loader_InitNodes(void* a0, PopReader_1C10C0* r)
{
    if (r->cur) {
        int mis;
        func_00165E60(func_001698C0(), D_0049EF70, 0);
        mis = (int)((unsigned long long)(unsigned int)r->cur & 3);
        if (mis)
            r->cur += 4 - mis;
        if ((unsigned char)Pop_FindTag(r, 0x3A444F4E)) {
            int n;
            Vec_1C10C0* list;
            int i;
            n = *(int*)r->cur;
            r->cur += 4;
            list = D_004FFBE0;
            if (n) {
                void* z[1];
                z[0] = 0;
                PtrVector_Resize(list, n, z);
            }
            for (i = 0; i < n; i++) {
                Node_1C10C0* p;
                Node_1C10C0** slot = &list->data[i];
                {
                    AllocGuard g;
                    p = (Node_1C10C0*)Mem_Alloc(0, 0x90, D_0049EE88, 0x519);
                }
                if (p)
                    p = Node_Construct(p, r, i);
                *slot = p;
                func_0040C940(list->data[i]);
                Node_1C10C0* q = list->data[i];
                if (q->flags & 0x200)
                    World_RegisterNode(D_004FFB50, q);
            }
        }
    }
}
#pragma opt_strength_reduction reset
