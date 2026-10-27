/*
 * SFOGame/Source/gameCanvas: 1 file, 00464D20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin GuiGameScreen_464D20 */
#pragma push /* merge_units */
#include "types.h"
#include "net_local_id.h"
#pragma inline_depth(10)
typedef struct { int prev; int next; void* obj; } N_464D20;
typedef struct { int n; N_464D20* head; } L_464D20;
typedef struct { char pad[0x28]; L_464D20 l; } M_464D20;
typedef struct { char pad[0x6A4]; void* f6A4; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; } G_464D20;
typedef struct { char pad[0x178]; int f178; } P_464D20;
typedef struct { char pad[0x6C]; unsigned char b6C; unsigned char b6D; char pad6E[2]; int f70; void* f74; } O_464D20;
extern void* D_00582CF0;
extern unsigned char D_00582B88;
unsigned int D_00497BF0[2] = { 0xFFFFFFFF, 0x0 };
extern unsigned char g_LoadoutPending;
extern void* D_004FFC04;
extern G_464D20* g_Hud;
extern P_464D20* g_LocalPlayer;
int HeadsetSemaphore_GetOwner(void* p);
int func_004651F0(void);
void func_00437950(int v);
int cDME_GetTime(int v);
int cGameFrontEnd_IsMessageBoxAwake_void_2(void* p);
int GuiGameScreen_IsChooseMenuActive(void* p);
void cHud_ActivateQuickChat(G_464D20* g);
M_464D20* Gui_Canvas(void);
void GuiCommonCanvas_NextFrame(O_464D20* o, float dt);

static inline int IsMine_464D20(void)
{
    void* p = D_00582CF0;
    if (p) {
        return HeadsetSemaphore_GetOwner(p) == NetLocalId();
    }
    return 0;
}

void func_00464D20(O_464D20* o, float dt)
{
    if (g_IsMultiplayer) {
        if (o->b6C) {
            unsigned char act = func_004651F0();
            if (!D_00582B88 || !act) {
                if (IsMine_464D20()) {
                    func_00437950(0);
                    (*(int*)D_00497BF0) = -1;
                    act = 0;
                    o->b6C = 0;
                    o->f70 = 0;
                    o->b6D = 0;
                }
            }
            if (act) {
                if (!o->b6D) {
                    o->b6D = 1;
                    o->f70 = cDME_GetTime(1) + 200;
                } else if (D_00582B88 && o->f70 < cDME_GetTime(1)) {
                    if (g_IsMultiplayer) {
                        func_00437950(1);
                    } else {
                        o->f70 = 0;
                        o->b6D = 0;
                    }
                }
            }
        } else {
            if (o->b6D) {
                if (!func_004651F0() || o->f70 < cDME_GetTime(1)) {
                    func_00437950(0);
                    (*(int*)D_00497BF0) = -1;
                } else if (!g_LoadoutPending && !cGameFrontEnd_IsMessageBoxAwake_void_2(D_004FFC04) && !g_Hud->b6A9 && !g_Hud->b6A8
                           && !g_Hud->b6AA && !GuiGameScreen_IsChooseMenuActive(g_Hud->f6A4) && !g_LocalPlayer->f178) {
                    cHud_ActivateQuickChat(g_Hud);
                }
            }
            o->f70 = 0;
            o->b6D = 0;
        }
        if (IsMine_464D20()) {
            int t = (*(int*)D_00497BF0);
            if (t > -1) {
                if (t < cDME_GetTime(1)) {
                    func_00437950(0);
                    (*(int*)D_00497BF0) = -1;
                    o->b6C = 0;
                }
            } else {
                (*(int*)D_00497BF0) = cDME_GetTime(1) + 15000;
            }
        } else {
            (*(int*)D_00497BF0) = -1;
        }
        {
            M_464D20* m = Gui_Canvas();
            L_464D20* l = &m->l;
            if (l->n) o->f74 = l->head->obj;
        }
    }
    GuiCommonCanvas_NextFrame(o, dt);
}
static inline void merge_flush_GuiGameScreen_464D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end GuiGameScreen_464D20 */
