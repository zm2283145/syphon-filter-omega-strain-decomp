#pragma cplusplus on
struct E337A0 { int id; int pad[4]; int val; };
extern "C" {
extern char D_00532B10[];
extern int D_00532B14;
E337A0** func_003305C0(void* v);
}
static inline bool Neq337A0(E337A0* a, E337A0* b) { return !(a == b); }
extern "C" int func_003337A0(int id)
{
    if (id > -1) {
        E337A0* first = *func_003305C0(D_00532B10);
        E337A0* last = *func_003305C0(D_00532B10) + D_00532B14;
        for (; Neq337A0(first, last); first++) {
            if (id == first->id)
                return first->val;
        }
    }
    return -1;
}