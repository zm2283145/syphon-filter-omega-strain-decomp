#include "types.h"
#pragma cplusplus on
struct EQBase { int a, b; };
struct EQEvent : EQBase { virtual ~EQEvent(); };
struct EQCmp {};
struct EQPred {
    EQCmp cmp;
    EQEvent** pp;
    EQPred(const EQCmp& c, EQEvent** p) : cmp(c), pp(p) {}
};
extern "C" {
extern unsigned char D_00533880;
extern int D_00533888;
extern char D_004BDFC8[];
extern EQEvent* D_0055A2F0;
extern char D_0055A2E0[];
void Alloc_Lock(int id);
void Alloc_Unlock(int id);
void Mem_Free(int pool, void* p, char* file, int line);
void ActiveList_EraseMatching(void* list, EQPred pred);
}

static inline void EQ_Delete(EQEvent* e)
{
    if (D_00533880)
        Alloc_Lock(9);
    D_00533888++;
    e->~EQEvent();
    Mem_Free(0, e, D_004BDFC8, 0x36);
    if (D_00533880)
        Alloc_Unlock(9);
    D_00533888--;
}
/* Removes an event from the active queue and destroys it. */
extern "C" void EventQueue_Remove(EQEvent* ev)
{
    if (D_0055A2F0 != ev) {
        EQCmp c __attribute__((aligned(8)));
        ActiveList_EraseMatching(D_0055A2E0, EQPred(c, &ev));
        EQ_Delete(ev);
    }
}