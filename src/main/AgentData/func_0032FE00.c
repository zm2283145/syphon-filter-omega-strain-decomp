#pragma opt_common_subs off
#pragma cplusplus on
#include "types.h"
struct E_32FE00 { int id; int pad[4]; int val; };
struct O_32FE00 { int key; int id; char flag; int a; int b; int val; };
extern "C" {
extern char g_UnlockRows[];
E_32FE00* std_vector_imp_Record_begin(void* t);
E_32FE00* std_vector_imp_Record_end(void* t);
void std_vector_Record_pointer2iterator(E_32FE00** out, void* t, E_32FE00** raw);
int nGlobalization_GetStringIndex(const char* key);
int nGlobalization_GetString_charP(int id);
}
static inline bool Neq_32FE00(E_32FE00* a, E_32FE00* b) { return !(a == b); }
static inline int Find_32FE00(const char* key)
{
    int k = nGlobalization_GetStringIndex(key);
    if (k > -1) {
        E_32FE00* b;
        E_32FE00* e;
        E_32FE00* t1;
        E_32FE00* t2;
        E_32FE00* first;
        t1 = std_vector_imp_Record_begin(g_UnlockRows);
        std_vector_Record_pointer2iterator(&b, g_UnlockRows, &t1);
        first = b;
        t2 = std_vector_imp_Record_end(g_UnlockRows);
        std_vector_Record_pointer2iterator(&e, g_UnlockRows, &t2);
        for (E_32FE00* last = e; Neq_32FE00(first, last); first++) {
            if (k == first->id) return first->val;
        }
    }
    return -1;
}
extern "C" O_32FE00* cAgentData_RatingRecord_ctor_charP_int_eScoreTypes_int_etc_2(O_32FE00* self, const char* name, int id, char flag, int a, int b, const char* key)
{
    self->key = nGlobalization_GetStringIndex(name);
    self->id = id;
    self->flag = flag;
    self->a = a;
    self->b = b;
    self->val = key ? Find_32FE00(key) : -1;
    return self;
}