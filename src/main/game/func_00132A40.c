#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

struct AlEq_c { char c; };
struct AlPred_c { AlEq_c op; void** ref; AlPred_c(const AlEq_c& e, void** r) : op(e), ref(r) {} };

extern "C" {
void Mem_Free(int pool, void* p, const char* file, int line);
void Object_Unregister(void*);
void TargetVis_Unregister(void*, void*);
void Object_DeleteLater(void*, float);
void* func_0013D9F0(void);
void func_00132B80(void*);
extern void ActiveList_EraseMatching(int* list, AlPred_c pred);
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

static inline void Erase_c(int* l, void** r) { AlEq_c eq; ActiveList_EraseMatching(l, AlPred_c(eq, r)); }
extern "C" void func_00132A40(World132A40* w)
{
    void* p;
    Erase_c(&w->list, &w->c0);
    TargetVis_Unregister(g_TargetVisMgr, w->c0);
    Object_Unregister(w->c0);
    Object_Unregister(w->d4);
    if (w->c0) {
        Object_DeleteLater(w->c0, 0.1f);
        w->c0 = 0;
    }
    if (w->d4) {
        Object_DeleteLater(w->d4, 0.1f);
        w->d4 = 0;
    }
    p = w->d0;
    if (p) {
        {
            AllocGuard g;
            Mem_Free(0, p, D_0049A890, 0x563);
        }
        func_00132B80(func_0013D9F0());
    }
}
