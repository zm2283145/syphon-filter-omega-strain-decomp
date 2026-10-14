/*
 * main/scriptManager: range (2 files, 003E0400-003E04C0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_003E0400 */
#pragma push /* merge_units */
#pragma cplusplus on
/* Script_LookupObjectById */
struct Pt2_ObjId { unsigned int v; int Hi() const { return (v & 0xFF0000) >> 16; } int Lo() const { return v & 0xFFFF; } };
struct Pt2_SObj { virtual void v0(); virtual void v1(); virtual void v2(); virtual Pt2_SObj* Resolve(); };
extern "C" {
Pt2_SObj* Object_LookupById(const Pt2_ObjId&);
void Script_PrintWarning(char*, int, int);
}
extern "C" Pt2_SObj* Script_LookupObjectById(unsigned int id) {
    Pt2_ObjId key;
    unsigned char direct;
    Pt2_SObj* o;
    direct = !((id & 0x80000000) != 0);
    key.v = id & 0x7FFFFFFF;
    o = Object_LookupById(key);
    if (!o) {
        if (key.Hi() || key.Lo()) Script_PrintWarning("gobj (%d/%d) not found", key.Hi(), key.Lo());
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
extern "C" int Script_ObjectToId(D2_ScriptObj* obj) {
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
