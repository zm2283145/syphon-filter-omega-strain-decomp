#pragma cplusplus on
struct E309C0 { int id; int val; int pad[4]; };
extern "C" {
extern char D_00532AF0[];
int func_0032E3F0(void* t);
int func_0032E3C0(void* t);
void func_0032E3E0(E309C0** out, void* t, int* raw);
int Loc_FindKeyThunk(__int128* key);
}
static inline bool Neq309C0(E309C0* a, E309C0* b) { return !(a == b); }
extern "C" int func_003309C0(__int128 key)
{
    E309C0* b;
    E309C0* e;
    int t1;
    int t2;
    E309C0* first;
    E309C0* last;
    int k;
    int r;
    t1 = func_0032E3F0(D_00532AF0);
    func_0032E3E0(&b, D_00532AF0, &t1);
    first = b;
    t2 = func_0032E3C0(D_00532AF0);
    func_0032E3E0(&e, D_00532AF0, &t2);
    last = e;
    k = Loc_FindKeyThunk(&key);
    for (; Neq309C0(first, last); first++) {
        if (k == first->id) {
            r = first->val;
            goto found;
        }
    }
    r = -1;
found:
    if (r < 0)
        r = 0;
    return r;
}