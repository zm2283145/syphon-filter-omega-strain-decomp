#pragma opt_common_subs off
#pragma cplusplus on
#include "types.h"
struct E_32FFD0 { int id; int pad[4]; int val; };
struct O_32FFD0 { int key; int p4; int key2; int c; int val; int x; };
extern "C" {
extern char g_UnlockRows[];
E_32FFD0* std_vector_imp_Record_begin(void* t);
E_32FFD0* std_vector_imp_Record_end(void* t);
void std_vector_Record_pointer2iterator(E_32FFD0** out, void* t, E_32FFD0** raw);
int Loc_FindKeyThunk(const char* key);
int Loc_LookupText(int id);
}
static inline bool Neq_32FFD0(E_32FFD0* a, E_32FFD0* b) { return !(a == b); }
static inline int Find_32FFD0(const char* key)
{
    int k = Loc_FindKeyThunk(key);
    if (k > -1) {
        E_32FFD0* b;
        E_32FFD0* e;
        E_32FFD0* t1;
        E_32FFD0* t2;
        E_32FFD0* first;
        t1 = std_vector_imp_Record_begin(g_UnlockRows);
        std_vector_Record_pointer2iterator(&b, g_UnlockRows, &t1);
        first = b;
        t2 = std_vector_imp_Record_end(g_UnlockRows);
        std_vector_Record_pointer2iterator(&e, g_UnlockRows, &t2);
        for (E_32FFD0* last = e; Neq_32FFD0(first, last); first++) {
            if (k == first->id) return first->val;
        }
    }
    return -1;
}
extern "C" O_32FFD0* AwardRow_Construct(O_32FFD0* self, const char* name, int x, const char* name2, int c, const char* key)
{
    self->key = Loc_FindKeyThunk(name);
    self->x = x;
    self->key2 = Loc_FindKeyThunk(name2);
    self->c = c;
    self->val = key ? Find_32FFD0(key) : -1;
    return self;
}