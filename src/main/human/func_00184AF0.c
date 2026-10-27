#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct V_4AF0 { __int128 q; V_4AF0() {} V_4AF0(const V_4AF0& o) { V_4AF0* pd = this; const V_4AF0* ps = &o; __int128 t; asm volatile { lq t, 0(ps); sq t, 0(pd) } } };
struct H_4AF0 {
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) virtual V_4AF0 GetPos();
    char pad4[0x28]; bool b2C; bool b2D; unsigned char b2E;
};
extern "C" {
extern signed char D_0049D023;
int cSKM_GOBJ_GetSkeleton_void(H_4AF0* h);
V_4AF0 cSkeleton_GetBoneToWorldTranslation(int skel, int node);
}static inline bool Use_4AF0(H_4AF0* h) { return h->b2D && h->b2C && !h->b2E; }
extern "C" V_4AF0 cHuman_GetLosPosition(H_4AF0* h)
{
    return Use_4AF0(h) ? cSkeleton_GetBoneToWorldTranslation(cSKM_GOBJ_GetSkeleton_void(h), D_0049D023) : h->GetPos();
}

