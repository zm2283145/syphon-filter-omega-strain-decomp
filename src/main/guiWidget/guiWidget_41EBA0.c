#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct W41EBA0;
struct H41EBA0 { VPAD8(a) VPAD4(b) VPAD1(c) virtual void OnEvent(W41EBA0* w, int kind, int x, int y); };
struct W41EBA0 { char pad[0x34]; float x; float y; char p3C[8]; H41EBA0* handler; };
extern "C" void func_0041EBA0(W41EBA0* w, float x, float y)
{
    w->x = x;
    w->y = y;
    if (w) w->handler->OnEvent(w, 0x12, (int)x, (int)y);
}
