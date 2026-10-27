#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct Pair132BC0 { short a; short b; };
struct Obj132BC0 { char pad[0x30]; int v30; char pad34[0x24]; int v58; };

extern "C" {
void* cMemMan_Allocate(int, int, char*, int);
void* cPlayerCamera_ctor(void*, int*, float);
void* Camera_ConstructFov(void*, int*, int, float);
void nGobjManager_AddGOBJ(void*);
void cTargetManager_AddGobj(void*, void*);
void cGameSystem_PushCamera(void*, void*);
void cPlayer_SetCamera(Obj132BC0*, void*);
void* cScene_ctor(void*, int);
void* GetSceneManager(void);
void cLList_cScenePtr_PushBackActual(void*, void* const&);
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

extern "C" void cGameSystem_CreatePlayerCameraAndScene(World132BC0* w)
{
    void* o;
    int k1;
    int k2;
    {
        AllocGuard g;
        o = cMemMan_Allocate(0, 0xDE0, D_0049A890, 0x53C);
    }
    if (o) {
        k1 = 0x620000;
        o = cPlayerCamera_ctor(o, &k1, 0.0f);
    }
    w->c0 = o;
    nGobjManager_AddGOBJ(w->c0);
    cTargetManager_AddGobj(g_TargetVisMgr, w->c0);
    cGameSystem_PushCamera(w, w->c0);
    {
        AllocGuard g;
        o = cMemMan_Allocate(0, 0xCF0, D_0049A890, 0x542);
    }
    if (o) {
        k2 = 0x620062;
        o = Camera_ConstructFov(o, &k2, 0, 1.134464f);
    }
    w->d4 = o;
    nGobjManager_AddGOBJ(w->d4);
    cPlayer_SetCamera(w->bc, w->c0);
    w->bc->v58 = w->bc->v30;
    {
        AllocGuard g;
        o = cMemMan_Allocate(0, 0xC, D_0049A890, 0x549);
    }
    if (o)
        o = cScene_ctor(o, w->bc->v30);
    w->d0 = o;
    {
        void* t = w->d0;
        cLList_cScenePtr_PushBackActual(GetSceneManager(), t);
    }
}


