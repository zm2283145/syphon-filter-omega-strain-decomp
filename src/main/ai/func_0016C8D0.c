#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct N_C8D0 { int pad0; int pad4; void* val; };
struct It_C8D0 { N_C8D0* n; It_C8D0() {} };
struct E_C8D0 { int a; E_C8D0() {} };
struct R_C8D0 { int a; R_C8D0() {} };
struct S_C8D0 { char pad[0x30]; char map[4]; };
extern "C" {
extern char D_0049C650[];
void Mem_Free(int pool, void* allocation, char* file, int line);
It_C8D0 NpcPerception_FindRecord(void* map, int key);
E_C8D0 func_0016BB80(void* map);
It_C8D0 func_0016BB90(const E_C8D0& e);
R_C8D0 func_0015AF40(const It_C8D0& it);
void List_Erase(void* out, void* map, const R_C8D0& r);
}
extern "C" void NpcPerception_RemoveAwareness(S_C8D0* self, int key)
{
    It_C8D0 it = NpcPerception_FindRecord(self->map, key);
    It_C8D0 end = func_0016BB90(func_0016BB80(self->map));
    if (it.n != end.n) {
        void* v = it.n->val;
        {
            AllocGuard g;
            Mem_Free(0, v, D_0049C650, 0x386);
        }
        {
            It_C8D0 pos = it;
            char out[4];
            R_C8D0 r = func_0015AF40(pos);
            List_Erase(out, self->map, r);
        }
    }
}