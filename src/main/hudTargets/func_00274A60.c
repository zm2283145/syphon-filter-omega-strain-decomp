#pragma cplusplus on
#include "types.h"
struct O274A60 { char p[0xC]; int id; char pad[0x6C - 0x10]; int f6C; };
struct H274A60 { int type; O274A60* p; int id; };
struct W274A60 { char pad[0x10]; H274A60 h; char str[4]; };
extern "C" int String_CStr(void*);
static inline O274A60* Get274A60(H274A60* h) {
    bool isNull;
    bool ok;
    O274A60* t;
    t = h->p;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->id != h->id) ok = false;
    return ok ? t : 0;
}
static inline O274A60* Deref274A60(H274A60* h) {
    bool isNull;
    O274A60* t;
    t = h->p;
    isNull = !t;
    return (isNull || t->id == h->id) ? t : 0;
}
extern "C" int func_00274A60(W274A60* w)
{
    if (w->h.type == 1) {
        if (Get274A60(&w->h)) return Deref274A60(&w->h)->f6C;
    } else if (w->h.type == 2) {
        return String_CStr(w->str);
    }
    return 0;
}


