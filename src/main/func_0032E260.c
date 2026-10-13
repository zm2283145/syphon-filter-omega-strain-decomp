#pragma opt_common_subs off
#pragma cplusplus on
#include "types.h"
struct E_32E260 { int id; int pad[4]; int val; };
struct O_32E260 { int text; int id; char flag; int a; int b; int c; int val; };
extern "C" {
extern char D_00532B10[];
E_32E260* func_0032E3F0(void* t);
E_32E260* func_0032E3C0(void* t);
void func_0032E3E0(E_32E260** out, void* t, E_32E260** raw);
int Loc_FindKeyThunk(const char* key);
int Loc_LookupText(int id);
}
static inline bool Neq_32E260(E_32E260* a, E_32E260* b) { return !(a == b); }
static inline int Find_32E260(const char* key)
{
    int k = Loc_FindKeyThunk(key);
    if (k > -1) {
        E_32E260* b;
        E_32E260* e;
        E_32E260* t1;
        E_32E260* t2;
        E_32E260* first;
        t1 = func_0032E3F0(D_00532B10);
        func_0032E3E0(&b, D_00532B10, &t1);
        first = b;
        t2 = func_0032E3C0(D_00532B10);
        func_0032E3E0(&e, D_00532B10, &t2);
        for (E_32E260* last = e; Neq_32E260(first, last); first++) {
            if (k == first->id) return first->val;
        }
    }
    return -1;
}
extern "C" O_32E260* func_0032E260(O_32E260* self, int id, char flag, const char* key, int a, int b, int c)
{
    self->text = Loc_LookupText(id);
    self->id = id;
    self->flag = flag;
    self->val = key ? Find_32E260(key) : -1;
    self->a = a;
    self->b = b;
    self->c = c;
    return self;
}
