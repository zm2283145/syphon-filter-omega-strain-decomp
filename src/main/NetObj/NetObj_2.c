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

extern int func_003FB750(int index);

/* Takes the 7-bit field in bits 24..30 of word +0x0C, converts it to a zero-based
 * index (clamped at 0) and forwards it to func_003FB750. */
int func_003FB720(NetObjFlags* obj) {
    int index = ((obj->flags & 0x7f000000) >> 24) - 1;
    if (index < 0) {
        index = 0;
    }
    return func_003FB750(index);
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
void func_003FC000(PsIt*, void*, int*);
void func_003FB8C0(PsIt*, void*);
PsIt* func_003FB8B0(PsIt*, PsIt*);
void func_003FC0C0(void* map, PsIt* it);
}
extern "C" int func_003FB750(int key)
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
        func_003FC000(&it, D_0055C770, &key);
        n = it.p;
        func_003FB8C0(&e, D_0055C770);
        func_003FB8B0(&e2, &e);
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
            func_003FC0C0(D_0055C770, &er);
            return 1;
        }
    }
    return 0;
}
#pragma pop /* merge_units */
/* merge_units: end func_003FB750 */
