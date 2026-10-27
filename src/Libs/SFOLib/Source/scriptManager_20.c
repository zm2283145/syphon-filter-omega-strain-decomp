/*
 * Libs/SFOLib/Source/scriptManager: 3 files, 003E03D0-003E0400
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003E03D0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern int std_vector_pod_int_insert(PtrVec* v, int* pos, int n, int value);

/* push_back: inserts one value at the end. */
int std_vector_StringPtr_push_back(PtrVec* v, int value) {
    return std_vector_pod_int_insert(v, v->data + v->count, 1, value);
}

void cScriptInterpreter_setInstructionPtr(ScriptManager* self, int value) {
    self->unk4E68 = value;
}
static inline void merge_flush_func_003E03D0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003E03D0 */

/* merge_units: begin func_003E0400 */
#pragma push /* merge_units */
#pragma cplusplus on
/* cScriptInterpreter_getObjPtr */
struct Pt2_ObjId { unsigned int v; int Hi() const { return (v & 0xFF0000) >> 16; } int Lo() const { return v & 0xFFFF; } };
struct Pt2_SObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual Pt2_SObj* Resolve(); };
extern "C" {
Pt2_SObj* nGobjManager_LookupGOBJ_cObjectIdR(const Pt2_ObjId&);
void cScriptBase_sm_printf(char*, int, int);
}
extern "C" Pt2_SObj* cScriptInterpreter_getObjPtr(unsigned int id) {
    Pt2_ObjId key;
    unsigned char direct;
    Pt2_SObj* o;
    direct = !((id & 0x80000000) != 0);
    key.v = id & 0x7FFFFFFF;
    o = nGobjManager_LookupGOBJ_cObjectIdR(key);
    if (!o) {
        if (key.Hi() || key.Lo()) cScriptBase_sm_printf("gobj (%d/%d) not found", key.Hi(), key.Lo());
    } else if (direct) {
        o = o->Resolve();
    }
    return o;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E0400(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E0400 */

/* merge_units: begin func_003E04C0 */
#pragma push /* merge_units */
#pragma cplusplus on
class D2_ScriptObj {
public:
    virtual void v0();
    virtual void v1();
    virtual int* GetId();
    int f4;
    int f8;
    int fC;
};
struct D2_SObj : public D2_ScriptObj { };
extern "C" int cScriptInterpreter_PackPtr(D2_ScriptObj* obj) {
    int id = -1;
    if (obj != 0) {
        id = *obj->GetId();
        if (id == obj->fC) id |= 0x80000000;
    }
    return id;
}
#pragma cplusplus reset
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_003E04C0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_003E04C0 */
