#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
class W3476B0 {
public:
    VPAD16(a) VPAD4(b)
    virtual bool IsA(void* type);
};
struct S3476B0 { char pad[0x78]; unsigned char a78; char pad79[7]; unsigned char a80; };
extern "C" {
extern "C" char D_004BA2D8[];
extern "C" char D_004BA2E8[];
static void * const dat_00492B88[2] = { (void*)D_004BA2D8, (void*)0x0 };
static void * const dat_00492B90[2] = { (void*)D_004BA2E8, (void*)0x0 };
extern char D_004A7520[];
extern char D_004FFB50[];
W3476B0* GuiWidget_FindChildByName(void* self, char* name);
void* Agent_GetSelected(void* list, int idx);
char* AgentData_GetName(void* ag);
char* AgentData_GetRankText(void* ag);
void GuiTextWidget_SetText(W3476B0* w, char* text, int flags);
void func_003476B0(S3476B0* o);
}
static inline W3476B0* cast3476B0(W3476B0* w)
{
    return (w && w->IsA(D_004A7520)) ? w : 0;
}
void func_003476B0(S3476B0* o)
{
    W3476B0* w;
    if (o->a80) return;
    w = cast3476B0(GuiWidget_FindChildByName(o, (*(char**)dat_00492B88)));
    if (w) GuiTextWidget_SetText(w, AgentData_GetName(Agent_GetSelected(D_004FFB50, -1)), 0);
    w = cast3476B0(GuiWidget_FindChildByName(o, (*(char**)dat_00492B90)));
    if (w) GuiTextWidget_SetText(w, AgentData_GetRankText(Agent_GetSelected(D_004FFB50, -1)), 0);
    o->a78 = 1;
    o->a80 = 1;
}