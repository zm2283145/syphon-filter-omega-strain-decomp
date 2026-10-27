#pragma cplusplus on
#include "types.h"
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




