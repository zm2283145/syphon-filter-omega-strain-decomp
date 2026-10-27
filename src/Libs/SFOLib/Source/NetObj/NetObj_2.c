/*
 * main/NetObj: 2 files, 003FB720-003FB750
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FB720 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NetObj_types.h"

extern int cNetObj_RemovePlayer_int(int index);

/* Takes the 7-bit field in bits 24..30 of word +0x0C, converts it to a zero-based
 * index (clamped at 0) and forwards it to cNetObj_RemovePlayer_int. */
int cNetObj_RemovePlayer_cGOBJP(NetObjFlags* obj) {
    int index = ((obj->flags & 0x7f000000) >> 24) - 1;
    if (index < 0) {
        index = 0;
    }
    return cNetObj_RemovePlayer_int(index);
}
#pragma pop /* merge_units */
/* merge_units: end func_003FB720 */

/* merge_units: begin func_003FB750 */
#pragma push /* merge_units */
#pragma cplusplus on
class VObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual bool Busy();
};
struct PsObj { char pad[0xC]; int serial; char pad10[0x48]; VObj* v;
    bool IsBusy() { bool r = false; if (v) { if (v->Busy()) r = true; } return r; } };
struct PsRef {
    PsObj* obj;
    int serial;
    PsObj* Get()
    {
        PsObj* o = obj;
        return (o == 0 || o->serial == serial) ? o : 0;
    }
};
struct PsNode { char pad[0x10]; PsRef ref; };
struct PsIt { PsNode* p; };
extern "C" {
extern char D_0055C770[];
void std_tree_pair_int_value_compare_cAllocator_pair_find_intR_2(PsIt*, void*, int*);
void std_map_int_cSafePtr_cGOBJ_cAllocator_pair_end(PsIt*, void*);
PsIt* cAssocArray_int_cSafePtr_cGOBJ_Iterator_ctor(PsIt*, PsIt*);
void std_tree_pair_int_value_compare_cAllocator_pair_erase(void* map, PsIt* it);
}
extern "C" int cNetObj_RemovePlayer_int(int key)
{
    if (key < 4 && key >= 0) {
        PsIt e2;
        PsIt it;
        PsIt er;
        PsIt e;
        PsNode* n;
        bool isnull;
        unsigned char valid;
        PsObj* o;
        PsRef* r;
        PsObj* got;
        std_tree_pair_int_value_compare_cAllocator_pair_find_intR_2(&it, D_0055C770, &key);
        n = it.p;
        std_map_int_cSafePtr_cGOBJ_cAllocator_pair_end(&e, D_0055C770);
        cAssocArray_int_cSafePtr_cGOBJ_Iterator_ctor(&e2, &e);
        if ((n == e2.p) ^ 1) {
            o = n->ref.obj;
            r = &n->ref;
            valid = 1;
            isnull = !o;
            if (!isnull && o->serial != r->serial) valid = 0;
            got = valid ? o : 0;
            if (got) {
                if (!((o == 0 || o->serial == r->serial) ? o : 0)->IsBusy()) return 0;
            }
            er.p = n;
            std_tree_pair_int_value_compare_cAllocator_pair_erase(D_0055C770, &er);
            return 1;
        }
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FB750 */
