#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Pair132BC0 { short a; short b; };
struct Obj132BC0 { char pad[0x30]; int v30; char pad34[0x24]; int v58; };

extern "C" {
void* Mem_Alloc(int, int, char*, int);
void* PlayerCamera_Construct(void*, int*, float);
void* Camera_ConstructFov(void*, int*, int, float);
void Object_Register(void*);
void TargetVis_Register(void*, void*);
void World_PushObjectFromAction(void*, void*);
void func_00176F30(Obj132BC0*, void*);
void* ZoneTracker_Ctor(void*, int);
void* func_0013D9F0(void);
void List_PushBack_132E20(void*, void* const&);
extern char D_0049A890[];
extern char g_TargetVisMgr[];
}

struct World132BC0 {
    char pad[0xBC];
    Obj132BC0* bc;
    void* c0;
    char padc4[0xC];
    void* d0;
    void* d4;
};

extern "C" void World_SetupView(World132BC0* w)
{
    void* o;
    int k1;
    int k2;
    {
        AllocGuard g;
        o = Mem_Alloc(0, 0xDE0, D_0049A890, 0x53C);
    }
    if (o) {
        k1 = 0x620000;
        o = PlayerCamera_Construct(o, &k1, 0.0f);
    }
    w->c0 = o;
    Object_Register(w->c0);
    TargetVis_Register(g_TargetVisMgr, w->c0);
    World_PushObjectFromAction(w, w->c0);
    {
        AllocGuard g;
        o = Mem_Alloc(0, 0xCF0, D_0049A890, 0x542);
    }
    if (o) {
        k2 = 0x620062;
        o = Camera_ConstructFov(o, &k2, 0, 1.134464f);
    }
    w->d4 = o;
    Object_Register(w->d4);
    func_00176F30(w->bc, w->c0);
    w->bc->v58 = w->bc->v30;
    {
        AllocGuard g;
        o = Mem_Alloc(0, 0xC, D_0049A890, 0x549);
    }
    if (o)
        o = ZoneTracker_Ctor(o, w->bc->v30);
    w->d0 = o;
    {
        void* t = w->d0;
        List_PushBack_132E20(func_0013D9F0(), t);
    }
}


