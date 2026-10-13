#pragma cplusplus on
#include "types.h"
struct S20 { char pad[0x14]; unsigned short f14; };
struct Mgr { char pad[0x20]; S20* p20; };
extern "C" {
extern void* D_004FFC04;
int func_002CAB70(void*);
Mgr* Gui_GetScreenStack(void);
}
/* Going through an inline wrapper keeps the bool locals from being folded. */
static inline Mgr* M() { return Gui_GetScreenStack(); }
extern "C" bool func_00241AC0(void)
{
    bool r = 1;
    if (!func_002CAB70(D_004FFC04)) {
        bool b = 0;
        bool a = 0;
        if (M() && M()->p20) a = 1;
        if (a) { if (M()->p20->f14 & 0x80) b = 1; }
        if (!b) r = 0;
    }
    return r;
}
