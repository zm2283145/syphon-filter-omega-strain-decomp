#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class C_2B1280 { public: VPAD16(a) VPAD2(b) VPAD1(c) virtual int IsLocal(); };
struct O_2B1280 { char pad[0xC]; unsigned int id; char pad10[0x48]; C_2B1280* ctl; };
struct G_2B1280 { char pad[0x30]; O_2B1280* obj; };
extern "C" { extern unsigned char g_IsMultiplayer; extern char g_Game[]; extern G_2B1280* g_LocalPlayer; int cGameSystem_GetClientPlayerLocation(void* list, int idx); }
static inline unsigned char Has_2B1280(O_2B1280* o)
{
    unsigned char r = 0;
    if (o->ctl && o->ctl->IsLocal()) r = 1;
    return r;
}
/* Looks up the local player's entry for the current object (-1 when there is none). */
extern "C" int GuiQuickChat_GetLocationID(void)
{
    if (g_LocalPlayer && g_LocalPlayer->obj) {
        O_2B1280* o = g_LocalPlayer->obj;
        int idx;
        if (g_IsMultiplayer) {
            if (Has_2B1280(o)) idx = ((o->id & 0x7F000000) >> 24) - 1;
            else idx = -1;
        } else {
            idx = 0;
        }
        return cGameSystem_GetClientPlayerLocation(g_Game, idx);
    }
    return -1;
}
