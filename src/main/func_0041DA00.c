#include "types.h"
#pragma cplusplus on
typedef struct S41DA { char p0[0x14]; unsigned short f14; char p16[0xE]; struct S41DA *f24; } S41DA;
static inline bool A41(S41DA *o) { bool r = 0; if ((o->f14 & 0x80) && (o->f14 & 4)) r = 1; return r; }
static inline bool B41(S41DA *o) { bool r = 0; if (A41(o) && (o->f14 & 2)) r = 1; return r; }
extern "C" bool GuiWidget_IsValidFocus(S41DA *o) {
    bool v = 1;
    if (o->f24 != o) {
        if (!B41(o)) v = 0;
    }
    return v;
}