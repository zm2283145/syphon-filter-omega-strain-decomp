/*
 * SFOGame/Source/GuiQuickChat: 3 files, 002B1120-002B1280
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002B1120 */
#pragma push /* merge_units */
#pragma cplusplus on

#include "types.h"
#include "vtable2_base_dtor.h"

/* Two-level destructor: restore vtables, run base destructor, optionally delete. */
DEFINE_VTABLE2_BASE_DTOR(cNetQuickChatMsg_dtor, D_004DE630, D_004DCF10, cMessage_dtor)
static inline void merge_flush_func_002B1120(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B1120 */

/* merge_units: begin func_002B1190 */
#pragma push /* merge_units */
extern char D_004ABEB8[];
extern char D_004ABEC8[];
extern char D_004ABED0[];
extern char D_00587C90[];
extern char* g_Hud;
extern int sprintf(char* buf, const char* fmt, ...);
extern char* nGlobalization_GetString_charP(char* key);
extern char* nGlobalization_GetString_int(int id);
extern char* nGlobalization_GetStringTag(int id);
extern void Libc_Strcpy(char* d, const char* s);
extern void cInfoBar_AddMessage(void* list, char* text, void* a, int b, int c);
#pragma opt_propagation off
void func_002B1190(int a, int b, int id)
{
    char name[0x20];
    char key[0x20];
    char out[0x200];
    char* fmt;
    char* txt;
    char* p;
    char* np = name;
    np[0] = 0;
    key[0] = 0;
    sprintf(key, D_004ABEB8, 0x1E, a, b);
    fmt = nGlobalization_GetString_charP(key);
    txt = 0;
    if (id > 0)
        txt = nGlobalization_GetString_int(id);
    p = nGlobalization_GetStringTag(id);
    if (p)
        Libc_Strcpy(np, p);
    sprintf(out, D_004ABEC8, fmt, txt ? txt : D_004ABED0);
    cInfoBar_AddMessage(g_Hud + 0x100, out, D_00587C90, 1, 0);
}


#pragma opt_propagation reset
static inline void merge_flush_func_002B1190(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B1190 */

/* merge_units: begin func_002B1280 */
#pragma push /* merge_units */
#pragma cplusplus on
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
static inline void merge_flush_func_002B1280(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002B1280 */
