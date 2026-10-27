/*
 * Libs/SFOLib/Source/NetObj: 4 files, 003FB4B0-003FB720
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003FB4B0 */
#pragma push /* merge_units */
#include "types.h"
#pragma push
#pragma cplusplus on
#include "alloc_guard.h"
#pragma pop

#pragma cplusplus on

struct Ctrl {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual unsigned char GetState();
};
struct NObj { char pad[0x49]; unsigned char type; char pad4A[0xE]; Ctrl* ctrl; };
struct NMap { int unk0; int unk4; };

extern "C" {
NMap* cNetObj_GetNetSystem(void);
NObj* nGobjManager_LookupGOBJ_cObjectIdR(int* id);
void* cMemMan_Allocate(int, int, char*, int);
void* cNPCInfoObject_ctor(void* p);
void cNPCInfoObject_SetOwner_uint_int(void* mgr, int id, int val);
extern void* D_0055C988;
extern char D_004BE228[];
}

extern "C" void cNetObj_SetOwner(int id, int val) {
    NMap* m = cNetObj_GetNetSystem();
    int key = id;
    NObj* o = nGobjManager_LookupGOBJ_cObjectIdR(&key);
    if (m) {
        if (o && o->ctrl && o->type == 2) {
            if (o->ctrl->GetState() == 2 || o->ctrl->GetState() == 1) {
            if (!D_0055C988) {
                void* p;
                {
                    AllocGuard g;
                    p = cMemMan_Allocate(0, 1, D_004BE228, 0x20C);
                }
                if (p) p = cNPCInfoObject_ctor(p);
                D_0055C988 = p;
            }
            cNPCInfoObject_SetOwner_uint_int(D_0055C988, id, val);
            } else {
                m->unk4 = val;
            }
        } else {
            m->unk4 = val;
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FB4B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FB4B0 */

/* merge_units: begin func_003FB650 */
#pragma push /* merge_units */
typedef struct NetRecvE6 {
    int key;
    int handler;
    int context;
} NetRecvE6;

extern unsigned char g_IsMultiplayer;
extern char D_0055C7A0[];
extern signed char D_0055C9B8;
extern int D_0055C9C0;
extern int D_0055C9C4;
extern unsigned char D_0055C9C8;
extern int D_0055C9CC;
extern int D_0055C9D0;
extern NetRecvE6* std_tree_pair_int_value_compare_find_or_insert(void* map, int* key);

/* Binds a receiver to a net id; offline returns a static dummy slot. */
int* cNetObj_AddSystem(int id, int context, int handler)
{
    int key[1];
    key[0] = id;
    if (g_IsMultiplayer) {
        std_tree_pair_int_value_compare_find_or_insert(D_0055C7A0, key)->handler = handler;
        std_tree_pair_int_value_compare_find_or_insert(D_0055C7A0, key)->context = context;
        return &std_tree_pair_int_value_compare_find_or_insert(D_0055C7A0, key)->handler;
    }
    if (D_0055C9B8 == 0) {
        D_0055C9C0 = 0;
        D_0055C9C4 = -1;
        D_0055C9C8 = 0;
        D_0055C9CC = 0;
        D_0055C9D0 = 0;
        D_0055C9B8 = 1;
    }
    return &D_0055C9C0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003FB650(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003FB650 */

/* merge_units: begin func_003FB720 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

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
static inline void merge_flush_func_003FB720(void) {} /* merge_units */
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
static inline void merge_flush_func_003FB750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003FB750 */
