#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct Obj_AD70 { char pad[0xC]; int serial; };
struct Handle_AD70 { Obj_AD70* obj; int serial; };
struct Node_AD70 { int f0; Node_AD70* next; Handle_AD70* handle; };
struct In_AD70 { Node_AD70* n; In_AD70() {} };
union It_AD70 { Node_AD70* n; };
struct Raw_AD70 { Node_AD70* n; };
struct R_AD70 { int a; R_AD70() {} };
struct Q_AD70 { int a; Q_AD70() {} };
struct E_AD70 { int a; E_AD70() {} };
extern "C" {
extern char g_NpcThinkList[];
extern char D_0049B670[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void List_Begin(void*, void*);
void func_0014ABC0(void*, void*);
void func_0014AB80(void*, void*);
void func_0014AB70(void*, void*);
void func_0015AF40(void*, void*);
void func_0015AF30(void*, void*);
void List_Erase(void*, void*, void*);
}
static inline int NonNull_AD70(Obj_AD70* p) { return p != 0; }
static inline Obj_AD70* Get_AD70(Handle_AD70* h) {
    bool ok = true;
    if ((NonNull_AD70(h->obj) ^ 1) == 0 && h->obj->serial != h->serial) ok = false;
    return ok ? h->obj : 0;
}
static inline void Er2(void* a, Raw_AD70* t) { char y[4], x[4]; func_0015AF30(x, a); List_Erase(y, g_NpcThinkList, x); func_0014ABC0(t, y); }
static inline void Er1(It_AD70* it, It_AD70* r) { Raw_AD70 t; char a[4]; func_0015AF40(a, it); Er2(a, &t); r->n = t.n; }
static inline void Bg2(It_AD70* b) { void* s; List_Begin(&s, g_NpcThinkList); func_0014ABC0(b, &s); }
static inline void Bg1(It_AD70* b) { Bg2(b); }
static inline void En2(It_AD70* e) { void* s; func_0014AB80(&s, g_NpcThinkList); func_0014AB70(e, &s); }
static inline void En1(It_AD70* e) { En2(e); }
extern "C" void NpcThinkList_RemoveActor(Obj_AD70* actor)
{
    It_AD70 it, r1, e, b;
    Bg1(&b);
    for (it.n = b.n; En1(&e), it.n != e.n; ) {
        Handle_AD70* h = it.n->handle;
        if (Get_AD70(h) == actor) {
            {
                AllocGuard g;
                Mem_Free(0, h, D_0049B670, 0x128);
            }
            Er1(&it, &r1);
            it = r1;
        } else {
            it.n = it.n->next;
        }
    }
}

