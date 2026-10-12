#pragma cplusplus on






#include "types.h"
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
