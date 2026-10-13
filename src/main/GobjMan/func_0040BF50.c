#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
#include "GobjMan_types.h"
/* Registered object; vtable slot 0 is the destructor. */
struct GobjVirt { virtual ~GobjVirt(); };
struct IdIter { int* p; };
extern "C" {
extern GobjScope* g_GobjRootScope;
extern unsigned char g_GobjDeleting;
extern char D_004BECA8[]; /* "GobjMan.cc" */
int func_0012F2B0(void); /* returns its argument + 0xC: here &obj->id */
void IdVec_Find(IdIter* out, PtrVec* v, int id);
void IdVec_End(IdIter* out, PtrVec* v);
int IdVecIter_Ne(IdIter* a, IdIter* b);
int IdMgr_IsOccupied(GobjScope* scope, int id);
void Mem_Free(int pool, void* allocation, char* file, int line);
}
/* True when the id is listed in the scope's id vector or no longer visible from it. */
static inline bool CanDelete(GobjScope* scope, int id)
{
    IdIter it;
    IdIter end;
    IdVec_Find(&it, (PtrVec*)&scope->ids, id);
    IdVec_End(&end, (PtrVec*)&scope->ids);
    return IdVecIter_Ne(&it, &end) || !IdMgr_IsOccupied(scope, id);
}
/* Deletes obj (with g_GobjDeleting set) when CanDelete allows it in the root scope. */
extern "C" void Gobj_TryDelete(GobjVirt* obj)
{
    GobjScope* root = g_GobjRootScope;
    int id = func_0012F2B0();
    if (CanDelete(root, id)) {
        g_GobjDeleting = 1;
        if (obj) {
            AllocGuard guard;
            obj->~GobjVirt();
            Mem_Free(0, obj, D_004BECA8, 0x11C);
        }
        g_GobjDeleting = 0;
    }
}