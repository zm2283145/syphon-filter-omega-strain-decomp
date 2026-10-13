#pragma opt_common_subs off
#pragma cplusplus on
#include "types.h"
struct E_32FE00 { int id; int pad[4]; int val; };
struct O_32FE00 { int key; int id; char flag; int a; int b; int val; };
extern "C" {
extern char D_00532B10[];
E_32FE00* func_0032E3F0(void* t);
E_32FE00* func_0032E3C0(void* t);
void func_0032E3E0(E_32FE00** out, void* t, E_32FE00** raw);
int Loc_FindKeyThunk(const char* key);
int Loc_LookupText(int id);
}
static inline bool Neq_32FE00(E_32FE00* a, E_32FE00* b) { return !(a == b); }
static inline int Find_32FE00(const char* key)
{
    int k = Loc_FindKeyThunk(key);
    if (k > -1) {
        E_32FE00* b;
        E_32FE00* e;
        E_32FE00* t1;
        E_32FE00* t2;
        E_32FE00* first;
        t1 = func_0032E3F0(D_00532B10);
        func_0032E3E0(&b, D_00532B10, &t1);
        first = b;
        t2 = func_0032E3C0(D_00532B10);
        func_0032E3E0(&e, D_00532B10, &t2);
        for (E_32FE00* last = e; Neq_32FE00(first, last); first++) {
            if (k == first->id) return first->val;
        }
    }
    return -1;
}
extern "C" O_32FE00* func_0032FE00(O_32FE00* self, const char* name, int id, char flag, int a, int b, const char* key)
{
    self->key = Loc_FindKeyThunk(name);
    self->id = id;
    self->flag = flag;
    self->a = a;
    self->b = b;
    self->val = key ? Find_32FE00(key) : -1;
    return self;
}