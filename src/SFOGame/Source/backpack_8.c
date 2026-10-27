/*
 * SFOGame/Source/backpack: 2 files, 002564A0-00256500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002564A0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Pair vector helpers (8-byte entries).
 */

#include "types.h"
#include "backpack_types.h"

extern int std_vector_imp_cSafePtr_cGOBJ_insert(PairVec* v, Pair* pos, int n, int value);

/* push_back(value) */
int cArray_cSafePtr_cGOBJ_PushBackActual(PairVec* v, int value) {
    return std_vector_imp_cSafePtr_cGOBJ_insert(v, v->data + v->count, 1, value);
}

int func_002564C0(Word* a, Word* b) {
    return a->value == b->value;
}

/* out = end() */
void cArray_cSafePtr_cGOBJ_End(Pair** out, PairVec* v) {
    *out = v->data + v->count;
}
static inline void merge_flush_func_002564A0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002564A0 */

/* merge_units: begin func_00256500 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Tgt { char pad[0xC]; int serial; };
struct Handle {
    Tgt* obj;
    int serial;
};
static inline Tgt* GetH(Handle* h) {
    Tgt* t;
    bool isNull;
    bool ok;
    t = h->obj;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->serial != h->serial) ok = false;
    return ok ? h->obj : 0;
}
struct HVec { int unk0; int count; Handle* data; };
extern "C" Handle** func_00256620(HVec* v);
static inline bool Valid(Handle* h) { bool isNull = !h->obj; return isNull || h->obj->serial == h->serial; }
static inline Tgt* GetH2(Handle* h) {
    return Valid(h) ? h->obj : 0;
}
static inline int NotEq(Handle* a, Handle* b) { return (a == b) ^ 1; }
extern "C" void cArray_cSafePtr_cGOBJ_Find(Handle** out, HVec* v, Handle* h)
{
    Handle* it = *func_00256620(v);
    Handle* end = *func_00256620(v) + v->count;
    while (NotEq(it, end)) {
        if (GetH(it) == GetH2(h)) {
            *out = it;
            return;
        }
        it++;
    }
    *out = end;
}
static inline void merge_flush_func_00256500(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00256500 */
