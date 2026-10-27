/*
 * main/GuiLobbyScreen: 4 files, 0033D310-0033D3F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0033D310 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "vslot_pad.h"
class C3D310 {
public:
    VPAD16(p) VPAD4(q) VPAD2(r)
    virtual void Slot22();
};
extern "C" unsigned char D_00532FE8;
extern "C" void GuiWidget_onAdvanceTime(C3D310* self);
extern "C" void func_0033D0C0(C3D310* self);
extern "C" void GuiLobbyScreen_onAdvanceTime(C3D310* self)
{
    GuiWidget_onAdvanceTime(self);
    self->Slot22();
    if (D_00532FE8)
        func_0033D0C0(self);
}
#pragma pop /* merge_units */
/* merge_units: end func_0033D310 */

/* merge_units: begin func_0033D360 */
#pragma push /* merge_units */
/* Compiled as C++ (virtual calls through $t9 only come from real virtual dispatch). */
#pragma cplusplus on
#include "types.h"

struct Object {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v0A(); virtual void v0B();
    virtual void v0C(); virtual void v0D(); virtual void v0E(); virtual void v0F(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void Method68(); /* +0x68 */
};

extern "C" void GuiWidget_onSleep(Object* self);

/* Calls GuiWidget_onSleep then virtual slot +0x68. */
extern "C" void GuiScreen_Sleep(Object* self)
{
    GuiWidget_onSleep(self);
    self->Method68();
}
#pragma pop /* merge_units */
/* merge_units: end func_0033D360 */

/* merge_units: begin func_0033D3A0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct Sub3D3A0 { char pad[0x10]; int state; };
class C3D3A0 {
public:
    VPAD16(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual void Slot23();
    char pad[0x78];
    Sub3D3A0* sub;
};
extern "C" void GuiWidget_onWake(C3D3A0* self);
extern "C" void GuiScreen_Wake(C3D3A0* self)
{
    GuiWidget_onWake(self);
    self->Slot23();
    if (self->sub)
        self->sub->state = -1;
}
#pragma pop /* merge_units */
/* merge_units: end func_0033D3A0 */

/* merge_units: begin func_0033D3F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit: GuiLobbyScreen.cc. Functions are named by address
 * until real names are known.
 */


extern char D_004B99C8[];
static void * const dat_004928A8[2] = { (void*)D_004B99C8, (void*)0x0 };
extern int GuiWidget_FindChild_charP(void* self, int a1);
extern int GuiWidget_onAdd(void* self);

void GuiLobbyScreen_onAdd(char* self) {
    GuiWidget_onAdd(self);
    *(int*)(self + 124) = GuiWidget_FindChild_charP(self, (*(int*)dat_004928A8));
}
#pragma pop /* merge_units */
/* merge_units: end func_0033D3F0 */
