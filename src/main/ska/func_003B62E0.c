#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

/* func_003B62E0: skeleton-set destructor (ska.cc): delete the owned objects of the vector at
 * +0x34, free the map values at +0x44 and the buffers of the vector at +0x14, run the member
 * destructors and free the object when the delete flag is positive. */

struct Obj { virtual void Destroy(int flag); };
struct It { void* p; };
struct Raw { void* p; };
struct MapNode { char pad[0x30]; void* value; };

struct SkSet {
    int x0;
    char v4[0x10];
    char v14[0x10];
    char v24[0x10];
    char v34[0x10];
    char m44[0x10];
};

extern "C" {
extern char D_004BCD70[];
void Mem_Free(int pool, void* p, char* file, int line);
void operator_delete(void* p);
void* func_003B6730(void* v);
void func_003B6720(It* out, void* v, void* const& r);
Raw func_003B6700(void* v);
void func_003B66F0(It* out, const Raw& r);
void func_003B66E0(It* out, void* m);
void func_003B66D0(It* out, void* m);
void Tree_Successor(It* it);
void* func_003B66C0(void* v);
void* func_003B6690(void* v);
void func_003B66B0(It* out, void* v, void* const& r);
void func_001C0570(void* p, int flag);
void func_001C0610(void* p, int flag);
void func_001C0750(void* p, int flag);
void func_00145F10(void* p, int flag);
void func_001C4480(void* p, int flag);
SkSet* func_003B62E0(SkSet* s, short flag);
}

static inline Raw MkRaw(void* p) { Raw r; r.p = p; return r; }
static inline int Eq(void* a, void* b) { return a == b; }

#pragma bool off
SkSet* func_003B62E0(SkSet* s, short flag)
{
    It itB;
    if (s) {
        {
            It e;
            It b;
            Obj* o;
            Obj** it;
            func_003B6720(&b, s->v34, func_003B6730(s->v34));
            it = (Obj**)b.p;
            while ((func_003B66F0(&e, func_003B6700(s->v34)), Eq(it, e.p) ^ 1)) {
                o = *it;
                {
                    AllocGuard g;
                    o->Destroy(-1);
                    Mem_Free(0, o, D_004BCD70, 0x35);
                }
                it++;
            }
        }
        {
            It b;
            It e;
            MapNode* end;
            func_003B66E0(&b, s->m44);
            itB = b;
            func_003B66D0(&e, s->m44);
            end = (MapNode*)e.p;
            while (Eq(itB.p, end) ^ 1) {
                void* v = ((MapNode*)itB.p)->value;
                {
                    AllocGuard g;
                    Mem_Free(0, v, D_004BCD70, 0x42);
                }
                Tree_Successor(&itB);
            }
        }
        {
            It b;
            It e;
            void** it;
            void** end;
            func_003B66B0(&b, s->v14, func_003B66C0(s->v14));
            it = (void**)b.p;
            func_003B66B0(&e, s->v14, func_003B6690(s->v14));
            end = (void**)e.p;
            /* volatile: retail re-reads e.p for the entry test (end is loaded in the delay slot) */
            if (Eq(it, *(void** volatile*)&e.p) ^ 1) {
                do {
                    void* v = *it;
                    {
                        AllocGuard g;
                        Mem_Free(0, v, D_004BCD70, 0x4F);
                    }
                    it++;
                } while (Eq(it, end) ^ 1);
            }
        }
        if (s->m44) func_001C0570(s->m44, -1);
        if (s->v34) func_001C0610(s->v34, -1);
        if (s->v24) func_001C0750(s->v24, -1);
        if (s->v14) func_00145F10(s->v14, -1);
        { void* p = s->v4; if (p) if (p) if (p) func_001C4480(p, 0); }
        if (flag > 0) operator_delete(s);
    }
    return s;
}
