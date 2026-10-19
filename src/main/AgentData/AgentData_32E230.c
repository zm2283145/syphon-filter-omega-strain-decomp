/*
 * main/AgentData: 2 files, 0032E230-0032E260
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0032E230 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "loose03_types.h"

/* Inserts count copies of *value at pos (vector insert). */
extern int func_00337F90(Vec28* v, Elem28* pos, int count, Elem28* value);

/* push_back: insert one element at the end. */
int func_0032E230(Vec28* v, Elem28* value) {
    return func_00337F90(v, &v->data[v->count], 1, value);
}
#pragma pop /* merge_units */
/* merge_units: end func_0032E230 */

/* merge_units: begin func_0032E260 */
#pragma push /* merge_units */
#pragma opt_common_subs off
#pragma cplusplus on
#include "types.h"
struct E_32E260 { int id; int pad[4]; int val; };
struct O_32E260 { int text; int id; char flag; int a; int b; int c; int val; };
extern "C" {
extern char g_UnlockRows[];
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
        t1 = func_0032E3F0(g_UnlockRows);
        func_0032E3E0(&b, g_UnlockRows, &t1);
        first = b;
        t2 = func_0032E3C0(g_UnlockRows);
        func_0032E3E0(&e, g_UnlockRows, &t2);
        for (E_32E260* last = e; Neq_32E260(first, last); first++) {
            if (k == first->id) return first->val;
        }
    }
    return -1;
}
extern "C" O_32E260* OmegaReqRow_Construct(O_32E260* self, int id, char flag, const char* key, int a, int b, int c)
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
#pragma pop /* merge_units */
/* merge_units: end func_0032E260 */
