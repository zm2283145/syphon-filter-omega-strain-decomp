#pragma cplusplus on
struct E308E0 { int id; int val; int pad[4]; };
extern "C" {
extern char D_00532B10[];
int func_0032E3F0(void* t);
int func_0032E3C0(void* t);
void func_0032E3E0(E308E0** out, void* t, int* raw);
int Loc_FindKeyThunk(__int128* key);
}
static inline bool Neq308E0(E308E0* a, E308E0* b) { return !(a == b); }
extern "C" int UnlockTable_FindBitByName(__int128 key)
{
    E308E0* b;
    E308E0* e;
    int t1;
    int t2;
    E308E0* first;
    E308E0* last;
    int k;
    int r;
    t1 = func_0032E3F0(D_00532B10);
    func_0032E3E0(&b, D_00532B10, &t1);
    first = b;
    t2 = func_0032E3C0(D_00532B10);
    func_0032E3E0(&e, D_00532B10, &t2);
    last = e;
    k = Loc_FindKeyThunk(&key);
    for (; Neq308E0(first, last); first++) {
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