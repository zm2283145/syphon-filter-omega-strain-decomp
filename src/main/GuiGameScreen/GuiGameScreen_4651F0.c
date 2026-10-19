/*
 * main/GuiGameScreen: 3 files, 004651F0-00465500
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_004651F0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
struct VO_4651F0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual char* Name();
};
typedef struct { int prev; int next; VO_4651F0* obj; } N_4651F0;
typedef struct { int n; N_4651F0* head; } L_4651F0;
typedef struct { char pad[0x28]; L_4651F0 l; } M_4651F0;
typedef struct { char pad[0x6A4]; void* f6A4; unsigned char b6A8; unsigned char b6A9; unsigned char b6AA; } G_4651F0;
typedef struct { char pad[0x178]; int f178; } P_4651F0;
typedef struct { char pad[0x6C]; unsigned char b6C; unsigned char b6D; char pad6E[2]; int f70; VO_4651F0* f74; } O_4651F0;
extern "C" {
extern unsigned int D_00497BF0[2];
extern unsigned char g_LoadoutPending;
extern void* D_004FFC04;
extern G_4651F0* g_Hud;
extern P_4651F0* g_LocalPlayer;
extern char D_004C2910[];
extern char D_004C2930[];
extern char D_004C2948[];
int String_CompareNoCase(char* a, char* b);
int func_002CAB70(void* p);
int GuiGameScreen_IsChooseMenuVisible(void* p);
M_4651F0* Gui_GetScreenStack(void);
}
static inline bool NotBusy(void) { return !g_Hud->b6AA && !GuiGameScreen_IsChooseMenuVisible(g_Hud->f6A4); }
extern "C" unsigned char func_004651F0(O_4651F0* o)
{
    unsigned char r;
    M_4651F0* m = Gui_GetScreenStack();
    L_4651F0* l = &m->l;
    r = 0;
    if (l->n) {
        VO_4651F0* obj = l->head->obj;
        if (obj == o->f74) {
            if (g_LoadoutPending) {
                if (!String_CompareNoCase(obj->Name(), D_004C2910) || !String_CompareNoCase(l->head->obj->Name(), D_004C2930))
                    r = 1;
            } else if (!String_CompareNoCase(obj->Name(), D_004C2948)) {
                r = NotBusy() && !g_LocalPlayer->f178;
            } else if (!func_002CAB70(D_004FFC04)) {
                r = g_Hud->b6A9 || g_Hud->b6A8;
            }
        } else {
            *(int*)D_00497BF0 = -1;
            o->b6C = 0;
            o->f70 = 0;
            o->b6D = 0;
        }
    }
    return r;
}
#pragma pop /* merge_units */
/* merge_units: end func_004651F0 */

/* merge_units: begin func_004653B0 */
#pragma push /* merge_units */
extern char g_Game[];
extern unsigned char D_00572400;
extern char D_00587310[], D_005874B0[], D_00587650[], D_005877F0[], D_00587990[];
void Game_EndLevel(void*, int);
extern int GuiSound_Play(void*, void*);
extern int GuiSound_Stop(void*, void*);
extern int func_00465A50(void*, void*, unsigned short, int, int);
int GuiGameCanvas_OnEvent(void* self, void* b, unsigned short type, int idx, int e)
{
    if (type == 0x1A && idx == 0x667) {
        Game_EndLevel(g_Game, D_00572400 ? 2 : 3);
        return 1;
    }
    if (type == 0x1A && idx == 0x668) {
        Game_EndLevel(g_Game, 3);
        return 1;
    }
    if (type == 0x10 || type == 0x11) {
        void* t = 0;
        switch (idx) {
        case 5: t = D_00587310; break;
        case 2: case 3: case 6: t = D_005874B0; break;
        case 7: t = D_00587650; break;
        case 8: t = D_005877F0; break;
        case 9: t = D_00587990; break;
        }
        if (t) {
            int r;
            if (type == 0x10) r = GuiSound_Play(b, t);
            else r = GuiSound_Stop(b, t);
            return r;
        }
    }
    return func_00465A50(self, b, type, idx, e);
}
#pragma pop /* merge_units */
/* merge_units: end func_004653B0 */

/* merge_units: begin func_00465500 */
#pragma push /* merge_units */
typedef struct { char pad[0x6C]; float t; } T465500;
extern void GuiCanvas_CheckControllers(T465500* p);
void GuiCanvas_Update(T465500* p, float dt) {
    float v;
    GuiCanvas_CheckControllers(p);
    v = p->t + 30.0f * dt;
    p->t = v;
    if (v > 300.0f) p->t = v - 300.0f;
}
#pragma pop /* merge_units */
/* merge_units: end func_00465500 */
