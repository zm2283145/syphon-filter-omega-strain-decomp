#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct V_F910 { __int128 q; V_F910() {} };
struct Obj_F910 { VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e) virtual V_F910 GetPos(); };
extern "C" {
void VisionFx_RequestFlash(void* fx, V_F910* pos, float a, float b, float c, float d);
extern void* D_004FFBDC;
}
/* request a vision flash (tremor) at the object position; duration c/3 */
extern "C" void Global_AddTremor(Obj_F910* o, float a, float b, float c)
{
    void* fx = D_004FFBDC;
    V_F910 p = o->GetPos();
    VisionFx_RequestFlash(fx, &p, a, b, c / 3.0f, c);
}
