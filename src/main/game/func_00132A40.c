#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct AlEq_c { char c; };
struct AlPred_c { AlEq_c op; void** ref; AlPred_c(const AlEq_c& e, void** r) : op(e), ref(r) {} };

extern "C" {
void cMemMan_Deallocate(int pool, void* p, const char* file, int line);
void nGobjManager_RemoveGOBJ(void*);
void cTargetManager_RemoveGobj(void*, void*);
void cSystem_ActualScheduleDelete(void*, float);
void* GetSceneManager(void);
void cLList_cScenePtr_Clear(void*);
extern void std_list_imp_voidPtr_remove_if(int* list, AlPred_c pred);
extern char D_0049A890[];
extern char g_TargetVisMgr[];
}

struct World132A40 {
    char pad[0xC0];
    void* c0;
    int list;
    char padc8[8];
    void* d0;
    void* d4;
};

static inline void Erase_c(int* l, void** r) { AlEq_c eq; std_list_imp_voidPtr_remove_if(l, AlPred_c(eq, r)); }
extern "C" void cGameSystem_DestroyPlayerCameraAndScene(World132A40* w)
{
    void* p;
    Erase_c(&w->list, &w->c0);
    cTargetManager_RemoveGobj(g_TargetVisMgr, w->c0);
    nGobjManager_RemoveGOBJ(w->c0);
    nGobjManager_RemoveGOBJ(w->d4);
    if (w->c0) {
        cSystem_ActualScheduleDelete(w->c0, 0.1f);
        w->c0 = 0;
    }
    if (w->d4) {
        cSystem_ActualScheduleDelete(w->d4, 0.1f);
        w->d4 = 0;
    }
    p = w->d0;
    if (p) {
        {
            AllocGuard g;
            cMemMan_Deallocate(0, p, D_0049A890, 0x563);
        }
        cLList_cScenePtr_Clear(GetSceneManager());
    }
}
