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
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
It_C8D0 cAITarget_cAwareList_Find(void* map, int key);
E_C8D0 std_list_cTargetAwarenessPtr_end_void(void* map);
It_C8D0 cLListIterator_cTargetAwarenessPtr_ctor(const E_C8D0& e);
R_C8D0 std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(const It_C8D0& it);
void std_list_deleter_voidPtr_erase_listdeleter(void* out, void* map, const R_C8D0& r);
}
extern "C" void cAITarget_RemoveAwareness(S_C8D0* self, int key)
{
    It_C8D0 it = cAITarget_cAwareList_Find(self->map, key);
    It_C8D0 end = cLListIterator_cTargetAwarenessPtr_ctor(std_list_cTargetAwarenessPtr_end_void(self->map));
    if (it.n != end.n) {
        void* v = it.n->val;
        {
            AllocGuard g;
            cMemMan_Deallocate(0, v, D_0049C650, 0x386);
        }
        {
            It_C8D0 pos = it;
            char out[4];
            R_C8D0 r = std_list_deleter_voidPtr_generic_iterator_ctor_listdeleterR(pos);
            std_list_deleter_voidPtr_erase_listdeleter(out, self->map, r);
        }
    }
}